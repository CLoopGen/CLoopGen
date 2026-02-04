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
    for (i = 0; i < 4; i++) {
        float sum = 0.F;
        for (j = 0; j < 4; j++) {
            if (wf[8 + i + (j << 2)] != 0.F)
                sum += vals[j] * wf[8 + i + (j << 2)];
        }
        if (i % 2 == 0)
            vals[4 + i] = sum + wf[8 + 16 + i];
        else
            vals[4 + i] = sum * 1.5F;
    }
}
