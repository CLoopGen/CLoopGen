#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *wf;
extern float vals[8];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    float sum = 0.F;
    for (j = 0; j < 2; j++) {
        if (i < 4 && j < 4)
            sum += vals[j] * wf[8 + i + (j << 2)];
    }
    if (i < 4)
        vals[4 + i] = sum + wf[24 + i];
}
}
