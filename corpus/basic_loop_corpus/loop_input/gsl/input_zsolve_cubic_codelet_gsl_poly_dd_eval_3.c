#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

#define DATA_SIZE (1 << 20)  // Approximately 1 million elements

double dd[DATA_SIZE];
double xa[DATA_SIZE];
size_t size = DATA_SIZE;
double x = 1.5;
size_t i;
double y;

void init_vars() {
    for (size_t idx = 0; idx < size; idx++) {
        dd[idx] = (double)(idx % 100) / 10.0;
        xa[idx] = (double)(idx % 200) / 50.0;
    }
    x = 1.5;
    y = 0.0;
}