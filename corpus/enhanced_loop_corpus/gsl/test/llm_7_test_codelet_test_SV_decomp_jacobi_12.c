#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern double lower;
extern double *a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 25; i += 2) {
        a[i] = lower;           // Remove loop-carried dependencies by enabling parallelism
        if (i + 1 < 25) {
            a[i + 1] = lower;   // Independent assignments within same iteration (no carry)
        }
    }
}
