#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float isf[20];
int i;
int i_max_corr;

void init_vars() {
    i_max_corr = 5;
    
    for (int idx = 0; idx < 20; idx++) {
        isf[idx] = (float)(idx * 3.14);
    }
}