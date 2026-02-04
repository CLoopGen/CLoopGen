#include <stdio.h>

#include <inttypes.h>

extern unsigned long NumberLeakyBuckets;
extern unsigned long *Rmin;
extern unsigned long i;
extern unsigned long j;
extern unsigned long temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < NumberLeakyBuckets; i++) {
        unsigned long min_idx = i;
        for (j = i + 1; j < NumberLeakyBuckets; j++) {
            if (Rmin[j] < Rmin[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            temp = Rmin[i];
            Rmin[i] = Rmin[min_idx];
            Rmin[min_idx] = temp;
        }
    }
}
