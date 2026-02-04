#include <stdio.h>

#include <inttypes.h>

typedef unsigned long Hashseq;

extern Hashseq hashprobe;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; i < (sizeof(Hashseq) * 2); i++) {
        if (i % 2 == 0) {
            hashprobe <<= 4;
            hashprobe |= (Hashseq)15;
        }
    }
}
