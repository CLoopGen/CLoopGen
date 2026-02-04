#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned long aa[100];
unsigned long ran_x[100];
unsigned int j;

void init_vars() {
    for (unsigned int i = 0; i < 100; i++) {
        ran_x[i] = (unsigned long)(i * 314159UL + 271828UL);
    }
}