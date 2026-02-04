#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int len;
extern int *diff;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (i = 0; i < len * 2; i += 2) {
    j = i % len;
    diff[j] <<= 7;
    diff[j] += 5;
}
}
