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
int step = 2;
for (k = 0; k < order; k += step) {
    int32_t temp = lpc[k] * 4096;
    row[k] = temp;
    DC_resp += lpc[k];
    if (k + 1 < order) {
        DC_resp += lpc[k + 1];
        row[k + 1] = lpc[k + 1] * 4096;
    }
}
}
