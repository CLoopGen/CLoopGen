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
for (n = 1; n < num; n += 2) {
    if (n + 1 < num && lsps[n] < lsps[n - 1]) {
        for (m = 2; m < num; m++) {
            double tmp = lsps[m];
            l = m - 1;
            while (l >= 0 && lsps[l] > tmp) {
                lsps[l + 1] = lsps[l];
                l--;
            }
            lsps[l + 1] = tmp;
        }
        break;
    }
}
}
