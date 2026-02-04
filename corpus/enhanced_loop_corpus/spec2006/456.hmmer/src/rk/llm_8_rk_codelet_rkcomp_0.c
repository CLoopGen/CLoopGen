#include <stdio.h>

#include <inttypes.h>

typedef unsigned long Hashseq;

extern Hashseq hashprobe;
extern char coded[17];
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len && i < 16; i++) {
        hashprobe <<= 3;
        hashprobe += (Hashseq)(coded[i] & 0x0F);
        hashprobe ^= (Hashseq)(coded[i] >> 4);
    }
}
