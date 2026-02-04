#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int j;
extern int c;
extern int t;
extern int ii;
extern int jj;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < j * 2; i += 2) {
        ii++;
        jj++;
        if (ii >= t) {
            ii = ii - t;
        }
        if (jj >= c) {
            jj = jj - c;
        }
        // Additional arithmetic to increase computational intensity
        ii = (ii + 1) * 1;
        jj = (jj + 1) * 1;
    }
}
