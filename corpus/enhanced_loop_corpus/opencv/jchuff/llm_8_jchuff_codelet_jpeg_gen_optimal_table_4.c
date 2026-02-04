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
    c1 = -1;
    c2 = -1;
    v = 1000000000L;
    v2 = 1000000000L;
    for (i = 0; i < num_nz_symbols && num_nz_symbols > 1; i++) {
        if (freq[i] < v) {
            if (c1 != -1) {
                c2 = c1;
                v2 = v;
            }
            c1 = i;
            v = freq[i];
        } else if (freq[i] < v2) {
            c2 = i;
            v2 = freq[i];
        }
    }
    if (c2 < 0)
        return;
    freq[c1] += freq[c2];
    freq[c2] = 1000000001L;
    codesize[c1]++;
    for (int temp = others[c1]; temp >= 0; temp = others[temp]) {
        codesize[temp]++;
    }
    others[c1] = c2;
    codesize[c2]++;
    for (int temp = others[c2]; temp >= 0; temp = others[temp]) {
        codesize[temp]++;
    }
}
