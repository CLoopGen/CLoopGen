#include <stdio.h>

#include <inttypes.h>

typedef unsigned long Hashseq;

extern char *sequence;
extern long i;
extern Hashseq target;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    long outer_limit = sizeof(Hashseq) * 2;
    for (long j = 0; j < 1; j++) {
        for (i = 0; i < outer_limit; i++) {
            if (*(sequence + i) == 0)
                break;
            target <<= 4;
            target |= (Hashseq)(*(sequence + i));
        }
    }
}
