#include <stdio.h>

#include <inttypes.h>

typedef unsigned long Hashseq;

extern Hashseq hashprobe;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int outer;
for (outer = 0; outer < 2; outer++) {
    for (; i < (sizeof(Hashseq) * 2); i++) {
        hashprobe <<= 4;
        hashprobe |= (Hashseq)15;
    }
}
}
