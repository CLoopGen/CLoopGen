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
    for (i = 0; i <= 256; i++) {
        if (freq[i] && freq[i] <= v) {
            v = freq[i];
            c1 = i;
        }
    }
    if (c1 < 0) break;

    c2 = -1;
    v = 1000000000L;
    for (i = 0; i <= 256; i++) {
        if (!(freq[i] && freq[i] <= v && i != c1)) {
            continue;
        }
        v = freq[i];
        c2 = i;
    }

    if (c2 < 0) break;

    freq[c1] += freq[c2];
    freq[c2] = 0;
    codesize[c1]++;

    if (others[c1] < 0) {
        others[c1] = c2;
    } else {
        int temp = others[c1];
        codesize[temp]++;
        others[c1] = c2;
        while (others[temp] >= 0) {
            temp = others[temp];
            codesize[temp]++;
        }
    }

    codesize[c2]++;
    if (others[c2] >= 0) {
        int temp = others[c2];
        codesize[temp]++;
        while (others[temp] >= 0) {
            temp = others[temp];
            codesize[temp]++;
        }
    }
}
}
