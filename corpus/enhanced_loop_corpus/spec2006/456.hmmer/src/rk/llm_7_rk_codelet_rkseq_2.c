#include <stdio.h>

#include <inttypes.h>

typedef unsigned long Hashseq;

extern char *sequence;
extern long i;
extern Hashseq target;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    Hashseq local_target = target; // Introduce loop-carried dependency on initial target
    long j;
    for (j = 0; j < (sizeof(Hashseq) * 2); j++) {
        if (*(sequence + j) == 0)
            break;
        local_target ^= (Hashseq)(*(sequence + j)); // Change from shift/or to XOR (WAW on local_target)
        local_target <<= 4;
    }
    target = local_target; // Single write at end to preserve semantics reasonably
}
