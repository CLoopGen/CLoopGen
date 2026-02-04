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
    INTFLOAT temp[3];
    for (m = 0; m < 3; m++)
        temp[m] = a[m] * g_decay_slope;
    for (m = 0; m < 3; m++)
        ag[m] = temp[m];
}
