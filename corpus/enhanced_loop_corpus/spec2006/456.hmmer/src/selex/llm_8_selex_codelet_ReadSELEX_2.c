#include <stdio.h>

#include <inttypes.h>

extern char **aseqs;
extern int num;
extern int seqidx;
extern int alen;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (seqidx = 0; seqidx < num; seqidx += 2) {
        if (seqidx < num) aseqs[seqidx][alen] = '\x00';
        if (seqidx + 1 < num) aseqs[seqidx + 1][alen] = '\x00';
    }
}
