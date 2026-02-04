#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *lsps;
extern int num;
extern int n;
extern int m;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (n = 1; n < num; n++) {
    int shouldBreak = 0;
    if (lsps[n] < lsps[n - 1]) {
        shouldBreak = 1;
        for (m = 1; m < num && shouldBreak; m++) {
            double tmp = lsps[m];
            for (l = m - 1; l >= 0; l--) {
                if (lsps[l] > tmp) {
                    lsps[l + 1] = lsps[l];
                } else {
                    break;
                }
            }
            lsps[l + 1] = tmp;
            shouldBreak = 0; // Only execute insertion sort once due to break in original
        }
    }
    if (shouldBreak) break;
}
}
