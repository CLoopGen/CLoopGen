#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *v2;
extern int len;
extern int i;
extern unsigned int *v1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse sequential access (access from end to beginning)
    for (i = len - 1; i >= 0; i--) {
        int t = v1[i] - v2[i];
        v1[i] += v2[i];
        v2[i] = t;
    }
}
