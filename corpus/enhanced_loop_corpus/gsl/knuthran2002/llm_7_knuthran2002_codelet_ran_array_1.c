#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long aa[];
extern unsigned int n;
extern unsigned int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    long temp_val;
    for (; j < n; j += 2) {
        if (j + 1 < n) {
            temp_val = ((aa[j - 100] - aa[j - 37]) & ((1L << 30) - 1));
            aa[j] = temp_val;
            aa[j + 1] = ((aa[j - 99] - aa[j - 36]) & ((1L << 30) - 1));
        } else {
            aa[j] = ((aa[j - 100] - aa[j - 37]) & ((1L << 30) - 1));
        }
    }
}
