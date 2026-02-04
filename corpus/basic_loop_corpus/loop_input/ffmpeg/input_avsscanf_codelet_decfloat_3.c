#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

uint32_t x[128];
int i;
int a;
int z;
double y;

void init_vars() {
    for (int j = 0; j < 128; j++) {
        x[j] = (uint32_t)rand();
    }
    i = 0;
    a = 0;
    z = 0;
    y = 0.0;
}