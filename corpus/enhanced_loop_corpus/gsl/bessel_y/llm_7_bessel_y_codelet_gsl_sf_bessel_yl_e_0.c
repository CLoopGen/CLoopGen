#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int l;
extern  double x;
extern double bym;
extern double by;
extern double byp;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double prev_bym, prev_by;
    prev_bym = bym;
    prev_by = by;
    for (j = 1; j < l; j++) {
        double new_byp = (2 * j + 1) / x * prev_by - prev_bym;
        prev_bym = prev_by;
        prev_by = new_byp;
    }
    bym = prev_bym;
    by = prev_by;
}
