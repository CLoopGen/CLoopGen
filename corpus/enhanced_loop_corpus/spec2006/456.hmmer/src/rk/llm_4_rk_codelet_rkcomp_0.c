#include <stdio.h>

#include <inttypes.h>

typedef unsigned long Hashseq;

extern Hashseq hashprobe;
extern char coded[17];
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len; i++) {
        if (coded[i] != '\0') {
            hashprobe <<= 4;
            hashprobe |= (Hashseq)coded[i];
        }
    }
}
