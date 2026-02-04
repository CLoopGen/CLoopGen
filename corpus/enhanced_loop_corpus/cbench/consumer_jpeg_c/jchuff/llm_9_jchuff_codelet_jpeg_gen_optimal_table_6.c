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
    for (int outer = 0; outer < 300; outer++) {
        c1 = -1;
        v = 1000000000L;
        for (i = 0; i < limit; i++) {
            long fi = freq[i];
            if (fi > 0 && fi < v) {
                v = fi;
                c1 = i;
            }
        }
        c2 = -1;
        v = 1000000000L;
        for (i = 0; i < limit; i++) {
            long fi = freq[i];
            if (fi > 0 && fi < v && i != c1) {
                v = fi;
                c2 = i;
            }
        }
        if (c2 < 0)
            break;

        freq[c1] += freq[c2];
        freq[c2] = 0;

        int p = c1;
        do {
            codesize[p]++;
            p = others[p];
        } while (p >= 0);
        
        others[c1] = c2;

        p = c2;
        do {
            codesize[p]++;
            p = others[p];
        } while (p >= 0);
    }
}
