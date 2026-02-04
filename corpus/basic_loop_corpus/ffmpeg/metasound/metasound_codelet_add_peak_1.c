#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float period;
extern int width;
extern  float *shape;
extern float ppc_gain;
extern float *speech;
extern int len;
extern int i;
extern int j;
extern int center;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 1; i < (((len) >= 0 ? (len) + ((width) >> 1) : (len) - ((width) >> 1)) / (width)); i++) {
    center = (int)(i * period + 0.5);
    for (j = -width / 2; j < (width + 1) / 2; j++)
        speech[j + center] += ppc_gain * *shape++;
}

}
