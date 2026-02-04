#include <stdio.h>

#include <inttypes.h>

typedef unsigned long Hashseq;

extern Hashseq hashprobe;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = sizeof(Hashseq) * 4;
    for (; i < limit; i += 2) {
        hashprobe <<= 3;
        hashprobe |= (Hashseq)7;
        hashprobe += (hashprobe >> 4);
    }
}
