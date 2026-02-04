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
if (num > 1) {
    for (n = 1; n < num && lsps[n] >= lsps[n - 1]; n++);
    if (n < num) {
        for (m = 1; m < num - 1; m++) {
            for (l = m; l > 0; l--) {
                if (lsps[l] >= lsps[l - 1]) break;
                double tmp = lsps[l];
                lsps[l] = lsps[l - 1];
                lsps[l - 1] = tmp;
            }
        }
    }
}
}
