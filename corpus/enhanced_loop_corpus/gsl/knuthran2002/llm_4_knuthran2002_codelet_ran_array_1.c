#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long aa[];
extern unsigned int n;
extern unsigned int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; j < n; j++) {
        if (j >= 100) {
            aa[j] = ((aa[j - 100] - aa[j - 37]) & ((1L << 30) - 1));
        }
    }
}
