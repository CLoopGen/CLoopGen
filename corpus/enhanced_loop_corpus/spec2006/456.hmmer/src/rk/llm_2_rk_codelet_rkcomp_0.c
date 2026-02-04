#include <stdio.h>

#include <inttypes.h>

typedef unsigned long Hashseq;

extern Hashseq hashprobe;
extern char coded[17];
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2 (forward traversal)
    for (i = 0; i < len; i += 2) {
        hashprobe <<= 4;
        hashprobe |= (Hashseq)coded[i];
    }
}
