#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dstU;
extern int16_t *dstV;
extern int width;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < width; i++) {
    int32_t u_val = dstU[i];
    int32_t v_val = dstV[i];
    u_val = u_val * 899 + 2040542;
    u_val = u_val * 2 + 1;
    dstU[i] = u_val >> 12;
    v_val = v_val * 899 + 2040542;
    v_val = v_val * 2 + 1;
    dstV[i] = v_val >> 12;
}
}
