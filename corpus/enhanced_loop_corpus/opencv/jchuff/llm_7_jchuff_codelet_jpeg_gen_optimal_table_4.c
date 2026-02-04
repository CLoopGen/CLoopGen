#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long freq[];
extern int codesize[257];
extern int others[257];
extern int c1;
extern int c2;
extern int i;
extern int num_nz_symbols;
extern long v;
extern long v2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (;;) {
    c1 = -1;
    c2 = -1;
    v = 1000000000L;
    v2 = 1000000000L;
    int candidate1 = -1, candidate2 = -1;
    long min1 = 1000000000L, min2 = 1000000000L;
    for (i = 0; i < num_nz_symbols; i++) {
        long fi = freq[i];
        if (fi < min1) {
            min2 = min1;
            candidate2 = candidate1;
            min1 = fi;
            candidate1 = i;
        } else if (fi < min2) {
            min2 = fi;
            candidate2 = i;
        }
    }
    c1 = candidate1;
    c2 = candidate2;
    v = min1;
    v2 = min2;
    if (c2 < 0)
        break;
    freq[c1] += freq[c2];
    freq[c2] = 1000000001L;
    codesize[c1]++;
    int next = others[c1];
    for (i = 0; i < num_nz_symbols && next >= 0; i++) {
        c1 = next;
        codesize[c1]++;
        next = others[c1];
    }
    others[c1] = c2;
    codesize[c2]++;
    next = others[c2];
    for (i = 0; i < num_nz_symbols && next >= 0; i++) {
        c2 = next;
        codesize[c2]++;
        next = others[c2];
    }
}
}
