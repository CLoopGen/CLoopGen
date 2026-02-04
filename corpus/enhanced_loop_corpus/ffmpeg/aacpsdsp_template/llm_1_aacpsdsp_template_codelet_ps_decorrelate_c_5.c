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
int outer, inner;
m = 0;
for (outer = 0; outer < 1; outer++) {
    for (inner = 0; inner < 3; inner++) {
        m = inner;
        ag[m] = a[m] * g_decay_slope;
    }
}
}
