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
for (m = 0; m < 3; m += 2) {
    ag[m] = a[m] * g_decay_slope;
    if (m + 1 < 3) {
        ag[m + 1] = a[m + 1] * g_decay_slope * 1.5f;
    }
}
}
