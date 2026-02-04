#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long aa[];
extern unsigned int n;
extern unsigned int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; j < n && j + 37 < n; j++) {
        long diff1 = aa[j - 100] - aa[j - 37];
        long diff2 = aa[j - 50] - aa[j - 20];
        long combined = (diff1 ^ diff2) + (diff1 & diff2);
        aa[j] = combined & ((1L << 30) - 1);
    }
}
