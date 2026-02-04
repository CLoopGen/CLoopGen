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
    for (m = 0; m < 3; ++m) {
        int temp_val = a[m];
        if (temp_val != 0) {
            ag[m] = (int)(((int64_t)temp_val * g_decay_slope + 536870912) >> 30);
        } else {
            ag[m] = 0;
        }
    }
}
