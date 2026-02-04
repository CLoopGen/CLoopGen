#include <stdio.h>

#include <inttypes.h>

typedef unsigned long Hashseq;

extern char *sequence;
extern long i;
extern Hashseq target;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int unroll_factor = 2;
    long limit = sizeof(Hashseq) * 2;
    for (i = 0; i < limit; i += unroll_factor) {
        for (int step = 0; step < unroll_factor; step++) {
            long idx = i + step;
            if (idx >= limit) break;
            if (*(sequence + idx) == 0)
                return;
            target <<= 4;
            target |= (Hashseq)(*(sequence + idx));
        }
    }
}
