#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t lpc[16];
extern int order;
extern int k;
extern int DC_resp;
extern int32_t *row;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32_t temp_sum = 0;
    for (k = 0; k < order; k++) {
        temp_sum += lpc[k];
        row[k] = lpc[k] * 4096;
    }
    DC_resp += temp_sum;
}
