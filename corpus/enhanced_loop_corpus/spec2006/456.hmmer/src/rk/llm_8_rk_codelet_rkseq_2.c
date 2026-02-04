#include <stdio.h>

#include <inttypes.h>

typedef unsigned long Hashseq;

extern char *sequence;
extern long i;
extern Hashseq target;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    long limit = sizeof(Hashseq) * 2;
    for (i = 0; i < limit && *(sequence + i) != 0; i++) {
        target <<= 4;
        target |= (Hashseq)(*(sequence + i));
        target ^= (target >> 8); // Additional arithmetic to increase computational intensity
    }
}
