#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int l;
extern  double x;
extern double bkp;
extern double bk;
extern double bkm;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double prev_bkm = bkm;
    double prev_bk = bk;
    double current_bk = bk;
    for (j = 1; j < l; j++) {
        double next_bkp = (2 * (j + 1) + 1) / x * current_bk + prev_bkm;
        prev_bkm = current_bk;
        prev_bk = next_bkp;
        if (j == l - 2) {
            bkp = next_bkp;
        }
        current_bk = prev_bk;
    }
    bk = current_bk;
    bkm = prev_bkm;
}
