#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float INTFLOAT;

extern INTFLOAT g_decay_slope;
extern  INTFLOAT a[];
extern INTFLOAT ag[3];
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (m = 0; m < 3; m++) {
        if (g_decay_slope > 0.0f) {
            ag[m] = a[m] * g_decay_slope;
        } else {
            ag[m] = 0.0f;
        }
    }
}
