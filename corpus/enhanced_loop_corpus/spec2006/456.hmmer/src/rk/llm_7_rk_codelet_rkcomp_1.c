#include <stdio.h>

#include <inttypes.h>

typedef unsigned long Hashseq;

extern Hashseq hashprobe;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    Hashseq local_hashprobe = hashprobe;
    for (; i < (sizeof(Hashseq) * 2); i++) {
        local_hashprobe <<= 4;
        if (i % 2 == 0) {
            local_hashprobe |= (Hashseq)5;
        } else {
            local_hashprobe |= (Hashseq)10;
        }
    }
    hashprobe = local_hashprobe;
}
