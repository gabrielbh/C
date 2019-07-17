#include <iostream>
#include <sys/time.h>
#include <cmath>
#include <iostream>
#include "osm.h"

#define MICRO_SEC_TO_NANO 1000
#define SEC_TO_NANO 1000000000

using namespace std;


double osm_operation_time(unsigned int iterations)
{
    if(iterations == 0)
    {
        iterations = 1000;
    }
    time_t startSec = 0, endSec = 0;
    suseconds_t startUsec = 0, endUsec = 0;
    timeval startTime = {startSec, startUsec};
    timeval endTime = {endSec, endUsec};
    int x = 0;
    gettimeofday(&startTime, nullptr);
    for(unsigned int i = 0; i < iterations; i++)
    {
        x++;
        x++;
        x++;
        x++;
        x++;
    }
    gettimeofday(&endTime, nullptr);
    double diffUsec = (endTime.tv_usec - startTime.tv_usec) * MICRO_SEC_TO_NANO;
    double diffSec = (endTime.tv_sec - startTime.tv_sec) * SEC_TO_NANO;
    double n = ((diffUsec + diffSec)  / x);
    return n;
}

void emptyFunc(){};

double osm_function_time(unsigned int iterations)
{
    if(iterations == 0)
    {
        iterations = 1000;
    }
    time_t startSec = 0, endSec = 0;
    suseconds_t startUsec = 0, endUsec = 0;
    timeval startTime = {startSec, startUsec};
    timeval endTime = {endSec, endUsec};
    int numOfActions = 5;
    gettimeofday(&startTime, nullptr);
    for(unsigned int i = 0; i < iterations; i++)
    {
        emptyFunc();
        emptyFunc();
        emptyFunc();
        emptyFunc();
        emptyFunc();
    }
    gettimeofday(&endTime, nullptr);
    double diffUsec = (endTime.tv_usec - startTime.tv_usec) * MICRO_SEC_TO_NANO;
    double diffSec = (endTime.tv_sec - startTime.tv_sec) * SEC_TO_NANO;
    double n = ((diffUsec + diffSec)  / (numOfActions * iterations));
    return n;
}

double osm_syscall_time(unsigned int iterations)
{
    if(iterations == 0)
    {
        iterations = 1000;
    }
    time_t startSec = 0, endSec = 0;
    suseconds_t startUsec = 0, endUsec = 0;
    timeval startTime = {startSec, startUsec};
    timeval endTime = {endSec, endUsec};
    int numOfActions = 5;
    gettimeofday(&startTime, nullptr);
    for(unsigned int i = 0; i < iterations; i++)
    {
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
    }
    gettimeofday(&endTime, nullptr);
    double diffUsec = (endTime.tv_usec - startTime.tv_usec) * MICRO_SEC_TO_NANO;
    double diffSec = (endTime.tv_sec - startTime.tv_sec) * SEC_TO_NANO;
    double n = ((diffUsec + diffSec)  / (numOfActions * iterations));
    return n;
}


int main() {
    cout << osm_operation_time(0) << endl;
    cout << osm_function_time(0) << endl;
    cout << osm_syscall_time(0) << endl;

}