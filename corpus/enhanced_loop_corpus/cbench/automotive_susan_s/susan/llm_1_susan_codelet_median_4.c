#include <stdio.h>

#include <inttypes.h>

extern int p[8];
extern int k;
extern int l;
extern int tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k < 7; k++) {
        for (int m = 0; m < (7 - k); m++) {
            for (l = m; l < m + 1; l++) {
                if (p[l] > p[l + 1]) {
                    tmp = p[l];
                    p[l] = p[l + 1];
                    p[l + 1] = tmp;
                }
            }
        }
    }
}
