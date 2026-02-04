#include <stdio.h>

#include <inttypes.h>

extern int p[8];
extern int k;
extern int l;
extern int tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k < 3; k++)
    for (l = 0; l < 4; l++) {
        int idx1 = 2 * l;
        int idx2 = 2 * l + 1;
        if (idx2 < 8 && p[idx1] > p[idx2]) {
            tmp = p[idx1];
            p[idx1] = p[idx2];
            p[idx2] = tmp;
        }
    }
}
