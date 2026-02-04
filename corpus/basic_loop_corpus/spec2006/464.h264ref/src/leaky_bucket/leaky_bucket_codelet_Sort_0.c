#include <stdio.h>

#include <inttypes.h>

extern unsigned long NumberLeakyBuckets;
extern unsigned long *Rmin;
extern unsigned long i;
extern unsigned long j;
extern unsigned long temp;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < NumberLeakyBuckets - 1; i++) {
    for (j = i + 1; j < NumberLeakyBuckets; j++) {
        if (Rmin[i] > Rmin[j]) {
            temp = Rmin[i];
            Rmin[i] = Rmin[j];
            Rmin[j] = temp;
        }
    }
}

}
