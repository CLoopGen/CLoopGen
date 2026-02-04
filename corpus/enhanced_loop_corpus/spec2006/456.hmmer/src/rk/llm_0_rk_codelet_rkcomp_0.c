#include <stdio.h>

#include <inttypes.h>

typedef unsigned long Hashseq;

extern Hashseq hashprobe;
extern char coded[17];
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (j = 0; j < len; j++) {
    for (i = 0; i <= j; i++) {
        hashprobe <<= 4;
        hashprobe |= (Hashseq)coded[i];
    }
}
}
