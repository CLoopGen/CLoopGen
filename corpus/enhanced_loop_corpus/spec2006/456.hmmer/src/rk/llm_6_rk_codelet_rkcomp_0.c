#include <stdio.h>

#include <inttypes.h>

typedef unsigned long Hashseq;

extern Hashseq hashprobe;
extern char coded[17];
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    Hashseq temp_hash = 0;
    for (i = 0; i < len; i++) {
        temp_hash <<= 4;
        temp_hash |= (Hashseq)coded[i];
    }
    hashprobe = temp_hash;
}
