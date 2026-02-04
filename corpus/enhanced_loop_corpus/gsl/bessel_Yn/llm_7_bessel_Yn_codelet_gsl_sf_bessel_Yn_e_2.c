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
    double local_bym = bym;
    double local_by = by;
    double prev_local_by;
    for (j = 1; j < n; j++) {
        prev_local_by = local_by;
        local_by = j * two_over_x * local_by - local_bym;
        local_bym = prev_local_by;
    }
    byp = local_by;
    bym = local_bym;
    by = local_by;
}
