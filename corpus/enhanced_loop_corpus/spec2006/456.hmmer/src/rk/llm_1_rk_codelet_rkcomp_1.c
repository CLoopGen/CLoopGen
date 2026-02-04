#include <stdio.h>

#include <inttypes.h>

typedef unsigned long Hashseq;

extern Hashseq hashprobe;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; i < (sizeof(Hashseq) * 2); i++) {
    for (int j = 0; j < 1; j++) {
        hashprobe <<= 4;
        hashprobe |= (Hashseq)15;
    }
}
}
