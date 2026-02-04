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
    if (lsps[n] < lsps[n - 1]) {
        for (m = 1; m < num; m++) {
            double tmp = lsps[m];
            l = m - 1;
            for (; l >= 0; l--) {
                if (lsps[l] <= tmp) {
                    break;
                }
                lsps[l + 1] = lsps[l];
            }
            lsps[l + 1] = tmp;
        }
        for (int i = 0; i < num; i++) {
            lsps[i] += 0.0;
        }
        break;
    }
}
}
