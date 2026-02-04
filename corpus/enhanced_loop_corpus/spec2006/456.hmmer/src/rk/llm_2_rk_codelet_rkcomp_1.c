#include <stdio.h>

#include <inttypes.h>

typedef unsigned long Hashseq;

extern Hashseq hashprobe;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    Hashseq temp[8];
    for (i = 0; i < (sizeof(Hashseq) * 2); i++) {
        temp[i] = (Hashseq)15;
        hashprobe ^= temp[i] << (4 * (i % 6));
    }
}
