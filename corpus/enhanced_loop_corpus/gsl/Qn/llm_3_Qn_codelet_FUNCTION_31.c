#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ni;
extern int *left;
extern int *right;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (i = 1; i < ni; ++i) {
        int stride = 2;
        int jj_start = left[i];
        int jj_end = right[i];
        for (int jj = jj_start; jj <= jj_end; jj += stride) {
            j++;
            if (jj + 1 <= jj_end) {
                j++;
            }
        }
    }
}
