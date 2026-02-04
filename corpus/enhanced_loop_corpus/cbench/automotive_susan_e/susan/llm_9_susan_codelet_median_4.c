#include <stdio.h>

#include <inttypes.h>

extern int p[8];
extern int k;
extern int l;
extern int tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k < 6; k++) {
        for (l = k + 1; l < 8; l++) {
            if (p[k] > p[l]) {
                tmp = p[k];
                p[k] = p[l];
                p[l] = tmp;
            }
        }
    }
}
