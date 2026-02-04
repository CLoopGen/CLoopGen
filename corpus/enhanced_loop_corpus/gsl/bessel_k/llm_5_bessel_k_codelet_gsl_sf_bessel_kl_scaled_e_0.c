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
    for (j = 1; j < l; j++) {
        double temp = (2 * j + 1) / x;
        if (temp > 1.0) {
            bkp = temp * bk + bkm;
        } else {
            bkp = bk + bkm;
        }
        bkm = bk;
        bk = bkp;
    }
}
