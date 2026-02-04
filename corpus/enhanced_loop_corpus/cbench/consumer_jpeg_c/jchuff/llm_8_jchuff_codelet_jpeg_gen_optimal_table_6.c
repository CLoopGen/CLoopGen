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
        for (i = 0; i < 257; i += 4) {
            if (i <= 256 && freq[i] && freq[i] <= v) {
                v = freq[i];
                c1 = i;
            }
            if (i + 1 <= 256 && freq[i+1] && freq[i+1] <= v) {
                v = freq[i+1];
                c1 = i + 1;
            }
            if (i + 2 <= 256 && freq[i+2] && freq[i+2] <= v) {
                v = freq[i+2];
                c1 = i + 2;
            }
            if (i + 3 <= 256 && freq[i+3] && freq[i+3] <= v) {
                v = freq[i+3];
                c1 = i + 3;
            }
        }
        c2 = -1;
        v = 1000000000L;
        for (i = 0; i < 257; i += 4) {
            if (i <= 256 && freq[i] && freq[i] <= v && i != c1) {
                v = freq[i];
                c2 = i;
            }
            if (i + 1 <= 256 && freq[i+1] && freq[i+1] <= v && (i+1) != c1) {
                v = freq[i+1];
                c2 = i + 1;
            }
            if (i + 2 <= 256 && freq[i+2] && freq[i+2] <= v && (i+2) != c1) {
                v = freq[i+2];
                c2 = i + 2;
            }
            if (i + 3 <= 256 && freq[i+3] && freq[i+3] <= v && (i+3) != c1) {
                v = freq[i+3];
                c2 = i + 3;
            }
        }
        if (c2 < 0)
            break;
        freq[c1] += freq[c2];
        freq[c2] = 0;
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
}
