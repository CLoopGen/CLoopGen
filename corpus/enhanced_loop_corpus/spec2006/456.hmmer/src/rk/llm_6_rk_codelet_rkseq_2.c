#include <stdio.h>

#include <inttypes.h>

typedef unsigned long Hashseq;

extern char *sequence;
extern long i;
extern Hashseq target;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    Hashseq temp = 0;
    long j;
    for (j = 0; j < (sizeof(Hashseq) * 2); j++) {
        char c = *(sequence + j);
        if (c == 0)
            break;
        temp <<= 4;
        temp |= (Hashseq)c;
    }
    target = temp; // Eliminate WAW and RAW dependencies on 'target' inside loop
}
