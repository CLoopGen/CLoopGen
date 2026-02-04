#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int n;
extern double two_over_x;
extern double bym;
extern double by;
extern double byp;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp_byp, temp_bym = bym;
    double temp_by = by;
    for (j = 1; j < n; j++) {
        temp_byp = j * two_over_x * temp_by - temp_bym;
        temp_bym = temp_by;
        temp_by = temp_byp;
    }
    byp = temp_byp;
    bym = temp_bym;
    by = temp_by;
}
