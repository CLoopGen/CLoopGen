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
    INTFLOAT prev = 0.0f;
    for (m = 0; m < 3; m++) {
        ag[m] = (a[m] + prev) * g_decay_slope;
        prev = ag[m];
    }
}
