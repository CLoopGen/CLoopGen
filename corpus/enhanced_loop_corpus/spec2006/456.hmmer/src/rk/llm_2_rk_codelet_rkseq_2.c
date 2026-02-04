#include <stdio.h>

#include <inttypes.h>

typedef unsigned long Hashseq;

extern char *sequence;
extern long i;
extern Hashseq target;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    long seq_len = sizeof(Hashseq) * 2;
    for (i = 0; i < seq_len; i += 2) {
        char c = *(sequence + i);
        if (c == 0)
            break;
        target <<= 4;
        target |= (Hashseq)c;
        if (i + 1 < seq_len) {
            char next_c = *(sequence + i + 1);
            if (next_c == 0)
                break;
            target <<= 4;
            target |= (Hashseq)next_c;
        }
    }
}
