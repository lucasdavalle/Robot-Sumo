#ifndef HEADER
#define	HEADER

//main!

struct {
    volatile unsigned mediciones_en_peligro_f : 2; //Utilizado para eliminar bugasos de los sensosres, al tomar 4 mediciones en peligro se actua.
    volatile unsigned mediciones_en_peligro_b : 2; //Utilizado para eliminar bugasos de los sensosres, al tomar 4 mediciones en peligro se actua.
    volatile unsigned mediciones_en_peligro_l : 2; //Utilizado para eliminar bugasos de los sensosres, al tomar 4 mediciones en peligro se actua.
    volatile unsigned mediciones_en_peligro_r : 2; //Utilizado para eliminar bugasos de los sensosres, al tomar 4 mediciones en peligro se actua.
    volatile unsigned nuevaMuestraFront : 1;
    volatile unsigned nuevaMuestraBack : 1;
    volatile unsigned nuevaMuestraLeft : 1;
    volatile unsigned nuevaMuestraRight : 1;
    volatile unsigned int_nuevaMuestraFront : 1;
    volatile unsigned int_nuevaMuestraBack : 1;
    volatile unsigned int_nuevaMuestraLeft : 1;
    volatile unsigned int_nuevaMuestraRight : 1;

    volatile unsigned detector_activado : 1;
    volatile unsigned robot_en_peligro : 1;

    volatile unsigned borde_detectado : 1; //Provoca salida de la ejecucion actual, procede acomodarse y buscar
    volatile unsigned borde_activado : 1;

    volatile unsigned int_delay_activado : 1;

    volatile unsigned sentidoBusqueda : 1;

    volatile unsigned manualOverride : 1;
} interrupt_flags;

uint8_t delayTmr(uint16_t miliSegundos); //Retorna 1 si ocurrio alguna de las interrupciones de arriba

#define DISTANCIA_PELIGROSA 10 //cm

void atacar();
void acomodarse();
void enPeligro();
void escapar();


uint8_t modoNonStop = 0;

//debug
/*
struct {
    volatile unsigned debugActivado : 1;
} debug_flags;

struct {
    uint8_t meds1;
    uint8_t meds2;
    uint8_t meds3;
    uint16_t sd;
    uint8_t pararAtaque;
    uint8_t modoNonStop;
}debug;

char vectorString[64];
void debugInit();
void debugTick();
void SERIAL_println(unsigned char *cadena);
//
//#define DEBUG_HABILITADO
 */
//api locomocion

#define MOV_ADELANTE 0
#define MOV_ATRAS 1
#define MOV_GIR_IZQ 2
#define MOV_GIR_DER 3

uint8_t ultimoMovimiento; //Almacena el ultimo movimiento conocido del robot!
/* Utilizar para: 
 * Acomodarse al tocar un borde
 * Elegir ruta de escape al detectar el robot en peligro
 * Elegir nueva tactica?
 */

#define constanteGiro 24.113 //24.166

void marcharAdelante();
void marcharAtras();

uint8_t marcharAdelanteTiempo(uint16_t tiempo);
uint8_t marcharAtrasTiempo(uint16_t tiempo);
uint8_t girarXgradosizquierda(uint16_t grados);
uint8_t girarXgradosderecha(uint16_t grados);
uint8_t giroLeveIzquierdaAvanzar(uint16_t tiempo);
uint8_t giroLeveDerechaAvanzar(uint16_t tiempo);
uint8_t giroLeveIzquierdaRetroceder(uint16_t tiempo);
uint8_t giroLeveDerechaRetroceder(uint16_t tiempo);
void detenerse();


//math_routines


char map(char x, char in_min, char in_max, char out_min, char out_max);
uint8_t arrayAverage(uint8_t* data, uint8_t n);
uint16_t calculateSD(uint8_t* data); //Tomar array de 4 datos!
uint8_t smallestValInArray(uint8_t* arr, uint8_t n);
uint8_t findClosest(uint8_t* arr, uint8_t n, uint8_t target);
uint8_t getClosest(uint8_t val1, uint8_t val2, uint8_t target);


#define mapSize 5 //0-6
#define mapMiddle 3
uint8_t targetMapDetection_subArrayAvg = 0;
uint8_t targetMapDetection(uint8_t * arr); //Retorna el indice mas certero de que sea el objetivo mas cercano

//drv_motores.c

#define PWMMOT_resolution 199

void motorIz_set(char a); //0 parado, 1 Adelante, 2 Atras
void motorDe_set(char a); //0 parado, 1 Adelante, 2 Atras
void setPwmIz(char pwm);
void setPwmDe(char pwm);

//drv_cny70.c
//api_detectorDeBordes.c

void drv_cny70_init();
void borde_isr();

struct {
    volatile unsigned frontleft : 1;
    volatile unsigned frontright : 1;
    volatile unsigned backleft : 1;
    volatile unsigned backright : 1;
} bordes;

void borde_detectado();

//logica

struct {
    uint8_t distancia;
    uint8_t lado;
} posInicio;

void detectarPosInicio();
void getLowestDistanceOnSensors_func();

struct {
    uint8_t lado_ID;
    uint8_t distancia;
} getLowestDistanceOnSensors;

#define LADO_ID_BACK    0
#define LADO_ID_FRONT   1
#define LADO_ID_LEFT    2
#define LADO_ID_RIGHT   3

//uint8_t buscar_peligro = 0;

struct buscar_t {
    uint16_t milis;
    uint8_t distMin;
    uint8_t lado_ID;
};

struct buscar_t med_final;
struct buscar_t med_front;
struct buscar_t med_back;
struct buscar_t med_left;
struct buscar_t med_right;


void buscar_t_init(struct buscar_t*, uint8_t sensID);

//void initBuscarMap(uint8_t * arr);

uint8_t buscarEnemigo(); //retorna 1 si se encontro exitosamente, 0 si se esta en peligro
//Actualiza med_final a los valores del sensor que detecto el peligro. usar id.


//Tacticas
//EDITABLE:

#define dist_tacticas_back_size 1
#define dist_tacticas_front_size 2
#define dist_tacticas_left_size 1
#define dist_tacticas_right_size 1

uint8_t dist_tacticas_back[dist_tacticas_back_size];
uint8_t dist_tacticas_front[dist_tacticas_front_size];
uint8_t dist_tacticas_left[dist_tacticas_left_size];
uint8_t dist_tacticas_right[dist_tacticas_right_size];

void tacticas_init();
void elegirTactica(uint8_t lado, uint8_t distancia);

//definicion de tacticas

//tactica 1: ejecutable en lado izquierdo
#define tactica_left_1_id 0
#define tactica_left_1_dist 30
void tactica_left_1();

//tactica 2: ejecutable en lado derecho
#define tactica_right_1_id 0
#define tactica_right_1_dist 20
void tactica_right_1();

//tactica 3: ejecutable en lado frente
#define tactica_front_1_id 0
#define tactica_front_1_dist 20
void tactica_front_1();

//tactica 4: ejecutable en lado frente
#define tactica_front_2_id 1
#define tactica_front_2_dist 50
void tactica_front_2();

//tactica 5: ejecutbale en lado atras
#define tactica_back_1_id 0
#define tactica_back_1_dist 20
void tactica_back_1();

void tactica_ejecutar(void);

void tactica_elegir(void (* tactica_funcion)(void));

extern void (*tactica_elegida)(void);

void tactica_default(void);

#endif	/* HEADER */