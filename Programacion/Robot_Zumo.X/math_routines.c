#include "mcc_generated_files/mcc.h"
#include "header.h"
#include <math.h>

char map(char x, char in_min, char in_max, char out_min, char out_max)
{
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


//uint8_t smallest(uint8_t* values, uint8_t count)
//{
//        uint8_t smallest_value = UINT8_MAX;
//        uint8_t ii = 0;
//        for (; ii < count; ++ii)
//        {
//                if (values[ii] < smallest_value)
//                {
//                        smallest_value = values[ii];
//                }
//        }
//        return smallest_value;
//}


// Returns element closest to target in arr[] 

/*
 * Calcular deviacion normal de 4 muestras
 * ejemplo
 * 10,15,20,25 - SD 5
 * 10,20,30,40 - SD 10
 * 
 * utilizado para saber si el sensor frontal se mamo al atacar, la deviacion salta por los aires.
 */

uint8_t arrayAverage(uint8_t* data, uint8_t n)
{
    uint16_t suma = 0;
    int i;
    for (i = 0; i < n; ++i)
    {
        suma += data[n];
    }

    return (suma / n);
}

uint16_t calculateSD(uint8_t* data) //Tomar array de 4 datos!
{
    float sum = 0.0;
    float standardDeviation = 0.0;

    int i;

    for (i = 0; i < 4; ++i)
    {
        sum += data[i];
    }

    float mean = sum / 4;

    for (i = 0; i < 4; ++i)
        standardDeviation += pow(data[i] - mean, 2);

    return round(sqrt(standardDeviation / 4));
}

uint8_t smallestValInArray(uint8_t* arr, uint8_t n)
{
    uint8_t smallest_value = UINT8_MAX;
    uint8_t ladoMenor;
    uint8_t i = 0;
    for (; i < n; ++i)
    {
        if (arr[i] < smallest_value)
        {
            smallest_value = arr[i];
            ladoMenor = i;
        }
    }
    return i;
}

uint8_t findClosest(uint8_t* arr, uint8_t n, uint8_t target)
{
    // Corner cases 
    if (target <= arr[0])
        //return arr[0];
        return 0;
    if (target >= arr[n - 1])
        //return arr[n - 1];
        return n - 1;

    // Doing binary search
    uint8_t i = 0;
    uint8_t j = n;
    uint8_t mid = 0;

    while (i < j)
    {
        mid = (i + j) / 2;

        if (arr[mid] == target)
            //return arr[mid];
            return mid;

        /* If target is less than array element, 
            then search in left */
        if (target < arr[mid])
        {

            // If target is greater than previous 
            // to mid, return closest of two 
            if (mid > 0 && target > arr[mid - 1])
            {
                uint8_t a = getClosest(arr[mid - 1], arr[mid], target);
                //return getClosest(arr[mid - 1], arr[mid], target);

                if (a == arr[mid - 1])
                    return mid - 1;
                else
                    return mid;
            }


            /* Repeat for left half */
            j = mid;
        }// If target is greater than mid 
        else
        {
            if (mid < n - 1 && target < arr[mid + 1])
            {
                uint8_t a = getClosest(arr[mid], arr[mid + 1], target);

                if (a == arr[mid])
                    return mid;
                else
                    return mid + 1;
            }
            //return getClosest(arr[mid],arr[mid + 1], target);
            // update i 
            i = mid + 1;
        }
    }

    // Only single element left after search 
    //return arr[mid];
    return mid;
}

// Method to compare which one is the more close. 
// We find the closest by taking the difference 
// between the target and both values. It assumes 
// that val2 is greater than val1 and target lies 
// between these two. 

uint8_t getClosest(uint8_t val1, uint8_t val2, uint8_t target)
{
    if (target - val1 >= val2 - target)
        return val2;
    else
        return val1;
}

uint8_t targetMapDetection(uint8_t * arr) //Retorna el indice mas certero de que sea el objetivo mas cercano
{
    uint8_t sumaSubArray_indiceMedio = 0;
    uint8_t SubArrayAvg_min = UINT8_MAX;
    
    uint8_t i = 0;
    uint8_t u = 0;
    for (; i < 70; ++i)
    {
        if (arr[i] < SubArrayAvg_min)
        {
            SubArrayAvg_min = arr[i];
            sumaSubArray_indiceMedio = i;
        }
    }
    targetMapDetection_subArrayAvg = SubArrayAvg_min;
    return sumaSubArray_indiceMedio;
}

//uint8_t targetMapDetection(uint8_t * arr) //Retorna el indice mas certero de que sea el objetivo mas cercano
//{
//    uint8_t subArray[mapSize];
//    uint8_t sumaSubArray_indiceMedio = 0;
//    uint8_t SubArrayAvg;
//    uint8_t SubArrayAvg_min = UINT8_MAX;
//    
//    uint8_t i = 0;
//    uint8_t u = 0;
//    for (; i < 50 - mapSize; ++i)
//    {
//        //sweep through array
//        u = 0;
//        for (; u < mapSize; ++u)
//        {
//            subArray[u] = arr[i + u];
//        }
//        
//        SubArrayAvg = arrayAverage(subArray, mapSize);
//        
//        if (SubArrayAvg < SubArrayAvg_min)
//        {
//            SubArrayAvg_min = SubArrayAvg;
//            sumaSubArray_indiceMedio = i + mapMiddle;
//        }
//    }
//    targetMapDetection_subArrayAvg = SubArrayAvg_min;
//    return sumaSubArray_indiceMedio;
//}