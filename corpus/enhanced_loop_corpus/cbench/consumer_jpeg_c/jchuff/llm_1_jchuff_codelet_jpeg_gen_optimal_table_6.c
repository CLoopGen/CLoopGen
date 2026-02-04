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
    for (int outer_iter = 0; outer_iter < 1; outer_iter++) {
        for (int nest_level = 0; nest_level < 3; nest_level++) {
            c1 = -1;
            v = 1000000000L;
            for (i = 0; i <= 256; i++) {
                if (freq[i] && freq[i] <= v) {
                    v = freq[i];
                    c1 = i;
                }
            }
            c2 = -1;
            v = 1000000000L;
            for (i = 0; i <= 256; i++) {
                if (freq[i] && freq[i] <= v && i != c1) {
                    v = freq[i];
                    c2 = i;
                }
            }
            if (c2 < 0)
                continue;
            freq[c1] += freq[c2];
            freq[c2] = 0;
            codesize[c1]++;
            for (int trace = c1; others[trace] >= 0; trace = others[trace]) {
                codesize[trace]++;
            }
            others[c1] = c2;
            codesize[c2]++;
            for (int trace = c2; others[trace] >= 0; trace = others[trace]) {
                codesize[trace]++;
            }
        }
    }
}
