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
for (int depth1 = 0; depth1 < order; depth1++) {
    DC_resp += lpc[depth1];
    row[depth1] = lpc[depth1] * 4096;
}
}
