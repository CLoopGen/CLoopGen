#include <stdio.h>

#include <inttypes.h>

extern char *s1;
extern char *s2;
extern int len;
extern int pos;
extern char c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 4;
    int unroll_factor = (len / 2 + 3) / 4;
    for (int block = 0; block < unroll_factor; block++) {
        int pos = block * step;
        int idx1 = len - pos - 1;
        int idx2 = len - (pos + 1) - 1;
        int idx3 = len - (pos + 2) - 1;
        int idx4 = len - (pos + 3) - 1;

        if (pos < len / 2) {
            c = s2[idx1];
            s1[idx1] = s2[pos];
            s1[pos] = c;
        }
        if (pos + 1 < len / 2) {
            c = s2[idx2];
            s1[idx2] = s2[pos + 1];
            s1[pos + 1] = c;
        }
        if (pos + 2 < len / 2) {
            c = s2[idx3];
            s1[idx3] = s2[pos + 2];
            s1[pos + 2] = c;
        }
        if (pos + 3 < len / 2) {
            c = s2[idx4];
            s1[idx4] = s2[pos + 3];
            s1[pos + 3] = c;
        }
    }
}
