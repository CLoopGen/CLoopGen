#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int INTFLOAT;

extern INTFLOAT g_decay_slope;
extern  INTFLOAT a[];
extern INTFLOAT ag[3];
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    INTFLOAT temp[3];
    for (m = 0; m < 3; m++)
        temp[m] = (int)(((int64_t)(a[m]) * (g_decay_slope) + 536870912) >> 30);
    for (m = 0; m < 3; m++)
        ag[m] = temp[m];
}
