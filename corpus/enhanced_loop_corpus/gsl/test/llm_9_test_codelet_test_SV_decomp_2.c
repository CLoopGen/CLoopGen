#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern double lower;
extern double *a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i += 2) {
    a[i] = lower;
    if (i + 1 < 8) {
        a[i + 1] = lower * 1.1;
    }
}
}
