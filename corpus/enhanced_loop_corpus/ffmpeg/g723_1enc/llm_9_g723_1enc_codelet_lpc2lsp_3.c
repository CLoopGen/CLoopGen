#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int f[12];
extern int max;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < 10; i++) {
        int val1 = (f[i] >= 0) ? f[i] : -f[i];
        int val2 = (f[i+1] >= 0) ? f[i+1] : -f[i+1];
        int candidate = (val1 > val2) ? val1 : val2;
        max = (max > candidate) ? max : candidate;
    }
}
