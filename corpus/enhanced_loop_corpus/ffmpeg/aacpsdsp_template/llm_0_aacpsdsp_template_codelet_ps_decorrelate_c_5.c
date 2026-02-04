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
int m_inner;
for (m = 0; m < 3; m++) {
    for (m_inner = 0; m_inner < 1; m_inner++) {
        ag[m] = a[m] * g_decay_slope;
    }
}
}
