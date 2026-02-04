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
    for (i = 0; i < num_nz_symbols; i += 2) {
        int idx1 = i;
        int idx2 = i + 1;
        long f1 = (idx2 <= num_nz_symbols) ? freq[idx1] : v2 + 1;
        long f2 = (idx2 < num_nz_symbols) ? freq[idx2] : v2 + 1;

        if (f1 <= v2) {
            if (f1 <= v) {
                c2 = c1;
                v2 = v;
                v = f1;
                c1 = idx1;
            } else {
                v2 = f1;
                c2 = idx1;
            }
        }
        if (f2 <= v2) {
            if (f2 <= v) {
                c2 = c1;
                v2 = v;
                v = f2;
                c1 = idx2;
            } else {
                v2 = f2;
                c2 = idx2;
            }
        }
    }
    if (c2 < 0)
        break;
    freq[c1] += freq[c2];
    freq[c2] = 1000000001L;
    codesize[c1]++;
    for (int j = 0; j < num_nz_symbols; j++) {
        int next = others[c1];
        if (next < 0) break;
        c1 = next;
        codesize[c1]++;
    }
    others[c1] = c2;
    codesize[c2]++;
    for (int j = 0; j < num_nz_symbols; j++) {
        int next = others[c2];
        if (next < 0) break;
        c2 = next;
        codesize[c2]++;
    }
}
}
