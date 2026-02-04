#include <stdio.h>

#include <inttypes.h>

typedef unsigned long Hashseq;

extern Hashseq hashprobe;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    Hashseq temp = hashprobe;
    for (int j = 0; j < (sizeof(Hashseq) * 2); j++) {
        temp <<= 4;
        temp |= (Hashseq)15;
    }
    hashprobe = temp;
}
