#include <stdio.h>

#include <inttypes.h>

typedef unsigned long Hashseq;

extern Hashseq hashprobe;
extern char coded[17];
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    hashprobe = 0;
    for (i = len - 1; i >= 0; i--) {
        hashprobe = (hashprobe << 4) | (hashprobe >> 28);
        hashprobe ^= (Hashseq)coded[i];
    }
}
