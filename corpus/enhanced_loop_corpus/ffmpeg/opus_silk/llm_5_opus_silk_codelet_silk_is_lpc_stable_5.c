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
    for (k = 0; k < order; k++) {
        DC_resp += (lpc[k] >= 0) ? lpc[k] : 0;
        row[k] = lpc[k] * 4096;
    }
}
