#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t nlsf[16];
int order;
uint16_t min_delta[17];
int i;

void init_vars() {
    order = 16;
    
    for (int j = 0; j < 16; j++) {
        nlsf[j] = rand() % 32767;
    }
    
    for (int j = 0; j < 17; j++) {
        min_delta[j] = rand() % 1000;
    }
}