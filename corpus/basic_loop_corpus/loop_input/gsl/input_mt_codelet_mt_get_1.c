#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned long UPPER_MASK = 0x80000000UL;
unsigned long LOWER_MASK = 0x7FFFFFFFUL;
int kk;

static unsigned long mt_array[624];

unsigned long * mt = mt_array;

void init_vars() {
    kk = 0;
    for (int i = 0; i < 624; i++) {
        mt[i] = rand();
    }
}