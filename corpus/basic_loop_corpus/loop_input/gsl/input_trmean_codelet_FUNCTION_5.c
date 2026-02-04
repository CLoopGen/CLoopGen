#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t ilow;
size_t ihigh;
double mean;
double k;
size_t i;

void init_vars() {
    ilow = 0;
    ihigh = 1000000;  
    mean = 0.0;
    k = 0.0;
}