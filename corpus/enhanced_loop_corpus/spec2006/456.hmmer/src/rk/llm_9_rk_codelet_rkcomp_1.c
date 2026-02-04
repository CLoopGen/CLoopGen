#include <stdio.h>

#include <inttypes.h>

typedef unsigned long Hashseq;

extern Hashseq hashprobe;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 1;
    int double_limit = sizeof(Hashseq) * 2 * 2;
    for (; i < double_limit; i += step) {
        hashprobe <<= 5;
        hashprobe |= (Hashseq)31;
        if ((hashprobe & 255) > 100) {
            hashprobe ^= 0xFF;
        }
    }
}
