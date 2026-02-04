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
        int found = 0;
        for (i = 0; i < num_nz_symbols; i++) {
            long fi = freq[i];
            if (fi <= v2) {
                if (fi <= v) {
                    c2 = c1;
                    v2 = v;
                    v = fi;
                    c1 = i;
                } else {
                    v2 = fi;
                    c2 = i;
                }
                found = 1;
            }
        }
        if (!found || c2 < 0)
            break;
        freq[c1] += freq[c2];
        freq[c2] = 1000000001L;
        codesize[c1]++;
        int next = others[c1];
        for (; next >= 0; ) {
            c1 = next;
            codesize[c1]++;
            next = others[c1];
        }
        others[c1] = c2;
        codesize[c2]++;
        next = others[c2];
        for (; next >= 0; ) {
            c2 = next;
            codesize[c2]++;
            next = others[c2];
        }
    }
}
