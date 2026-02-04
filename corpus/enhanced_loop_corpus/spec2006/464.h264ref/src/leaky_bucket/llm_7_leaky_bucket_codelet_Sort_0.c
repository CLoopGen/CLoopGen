#include <stdio.h>

#include <inttypes.h>

extern unsigned long NumberLeakyBuckets;
extern unsigned long *Rmin;
extern unsigned long i;
extern unsigned long j;
extern unsigned long temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < NumberLeakyBuckets; i++) {
        temp = Rmin[i];
        j = i;
        for (; j > 0 && Rmin[j - 1] > temp; j--) {
            Rmin[j] = Rmin[j - 1];
        }
        Rmin[j] = temp;
    }
}
