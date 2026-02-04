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
    for (;;) {
        c1 = -1;
        v = 1000000000L;
        for (i = 256; i >= 0; i--) {
            if (freq[i] && freq[i] <= v) {
                v = freq[i];
                c1 = i;
            }
        }
        c2 = -1;
        v = 1000000000L;
        for (i = 256; i >= 0; i--) {
            if (freq[i] && freq[i] <= v && i != c1) {
                v = freq[i];
                c2 = i;
            }
        }
        if (c2 < 0)
            break;
        freq[c1] += freq[c2];
        freq[c2] = 0;
        codesize[c1]++;
        for (int temp = others[c1]; temp >= 0; ) {
            codesize[temp]++;
            temp = others[temp];
        }
        others[c1] = c2;
        codesize[c2]++;
        for (int temp = others[c2]; temp >= 0; ) {
            codesize[temp]++;
            temp = others[temp];
        }
    }
}
