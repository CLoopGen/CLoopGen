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
    double temp_byp;
    for (j = 1; j < l; j++) {
        temp_byp = (2 * j + 1) / x * by - bym;
        bym = by;
        by = temp_byp;
    }
}
