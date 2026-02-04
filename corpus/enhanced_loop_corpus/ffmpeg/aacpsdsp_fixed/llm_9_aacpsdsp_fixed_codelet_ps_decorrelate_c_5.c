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
for (m = 0; m < 6; m += 2) {
    int idx = m < 3 ? m : 5 - m;
    int64_t product = (int64_t)(a[idx]) * g_decay_slope;
    ag[idx] = (int)((product + 536870912 + (1 << (m % 3))) >> 30);
    if (m + 1 < 3) {
        int next_idx = m + 1;
        ag[next_idx] = (int)(((int64_t)(a[next_idx]) * g_decay_slope + 536870912 - (1 << ((m + 1) % 3))) >> 30);
    }
}
}
