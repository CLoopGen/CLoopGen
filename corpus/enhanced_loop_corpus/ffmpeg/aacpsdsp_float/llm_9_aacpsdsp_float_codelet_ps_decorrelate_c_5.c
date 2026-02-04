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
for (m = 0; m < 1; m++) {
    ag[0] = a[0] * g_decay_slope;
    ag[1] = a[1] * g_decay_slope * a[0];
    ag[2] = a[2] * g_decay_slope * a[0] * a[1];
}
}
