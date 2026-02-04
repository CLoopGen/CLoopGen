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
    // Variant 2: Reverse sequential access from end to beginning
    for (i = len - 1; i >= 0; i--)
        p += (int64_t)v1[i] * v2[i];
}
