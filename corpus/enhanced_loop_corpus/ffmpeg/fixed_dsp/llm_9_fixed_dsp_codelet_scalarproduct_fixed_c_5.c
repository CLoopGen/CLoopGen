#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int *v1;
extern  int *v2;
extern int len;
extern int64_t p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len && i < 1000; i++) {
        int64_t prod = (int64_t)v1[i] * v2[i];
        p += prod > 0 ? prod : -prod;
    }
}
