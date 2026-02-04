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
    float sum = vals[0] * wf[8 + i]; // Introduce fixed index dependency to break some RAW
    for (j = 1; j < 4; j++)
        sum += vals[j] * wf[8 + i + (j << 2)];
    vals[i] = sum + wf[24 + i]; // WAW hazard introduced: overwriting vals[0..3] instead of vals[4..7]
}

}
