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
    long temp_freq[257];
    for (i = 0; i < num_nz_symbols; i++) {
        temp_freq[i] = freq[i];
    }
    for (i = 0; i < num_nz_symbols; i++) {
        if (temp_freq[i] <= v2) {
            if (temp_freq[i] <= v) {
                c2 = c1;
                v2 = v;
                v = temp_freq[i];
                c1 = i;
            } else {
                v2 = temp_freq[i];
                c2 = i;
            }
        }
    }
    if (c2 < 0)
        break;
    freq[c1] += freq[c2];
    freq[c2] = 1000000001L;
    codesize[c1]++;
    int temp_c1 = others[c1];
    for (int j = 0; j < num_nz_symbols && temp_c1 >= 0; j++) {
        c1 = temp_c1;
        codesize[c1]++;
        temp_c1 = others[c1];
    }
    others[c1] = c2;
    codesize[c2]++;
    int temp_c2 = others[c2];
    for (int j = 0; j < num_nz_symbols && temp_c2 >= 0; j++) {
        c2 = temp_c2;
        codesize[c2]++;
        temp_c2 = others[c2];
    }
}
}
