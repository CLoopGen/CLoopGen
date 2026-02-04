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
    double temp_bk = bk;
    double temp_bkm = bkm;
    for (j = 1; j < l; j++) {
        double new_bkp = (2 * j + 1) / x * temp_bk + temp_bkm;
        temp_bkm = temp_bk;
        temp_bk = new_bkp;
    }
    bk = temp_bk;
    bkm = temp_bkm;
}
