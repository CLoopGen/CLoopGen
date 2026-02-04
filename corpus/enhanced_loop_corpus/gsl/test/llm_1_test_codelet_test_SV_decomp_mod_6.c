#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern double lower;
extern double *a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    int offset = i * 4;
    for (int k = 0; k < 4; k++) {
        a[offset + k] = lower;
    }
}
}
