#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float lpcf[16];
extern int order;
extern int i;
extern int16_t lpc[16];

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < order; i++)
    lpcf[i] = lpc[i] / 4096.F;

}
