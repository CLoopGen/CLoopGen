#include <stdio.h>

#include <inttypes.h>

extern char **aseqs;
extern int num;
extern int seqidx;
extern int alen;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (seqidx = 0; seqidx < num; seqidx++) {
        char *current_seq = aseqs[seqidx];
        current_seq[alen] = '\x00';
    }
}
