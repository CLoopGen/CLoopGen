#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t nops[10000];
extern int i;
extern int nop_sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_sum1 = 0;
    int temp_sum2 = 0;
    for (i = 2500; i < 7500; i += 2) {
        temp_sum1 += nops[i];
        if (i + 1 < 7500) {
            temp_sum2 += nops[i + 1];
        }
    }
    nop_sum += temp_sum1 + temp_sum2;
}
