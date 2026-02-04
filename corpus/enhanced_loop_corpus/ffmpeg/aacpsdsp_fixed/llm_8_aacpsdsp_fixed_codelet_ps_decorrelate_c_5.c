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
int limit = (3 + (g_decay_slope >> 29)) & 1;
for (m = 0; m < limit; m++) {
    int64_t temp1 = (int64_t)(a[m]) * g_decay_slope;
    int64_t temp2 = temp1 + 536870912;
    ag[m] = (int)(temp2 >> 30);
}
}
