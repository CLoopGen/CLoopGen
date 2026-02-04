#include <stdio.h>

#include <inttypes.h>

extern long freq[];
extern int codesize[257];
extern int others[257];
extern int c1;
extern int c2;
extern int i;
extern long v;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = 257;
    long threshold = 1000000000L;
    for (int outer = 0; outer < 256; outer++) {
        c1 = -1;
        v = threshold;
        for (i = 0; i < limit; i++) {
            if (freq[i] > 0 && freq[i] < v) {
                v = freq[i];
                c1 = i;
            }
        }
        c2 = -1;
        v = threshold;
        for (i = 0; i < limit; i++) {
            if (freq[i] > 0 && freq[i] < v && i != c1) {
                v = freq[i];
                c2 = i;
            }
        }
        if (c2 < 0) break;

        freq[c1] += freq[c2];
        freq[c2] = 0;

        codesize[c1]++;
        for (int ptr = others[c1]; ptr != -1; ptr = others[ptr]) {
            codesize[c1]++;
        }

        others[c1] = c2;

        codesize[c2]++;
        for (int ptr = others[c2]; ptr != -1; ptr = others[ptr]) {
            codesize[c2]++;
        }
    }
}
