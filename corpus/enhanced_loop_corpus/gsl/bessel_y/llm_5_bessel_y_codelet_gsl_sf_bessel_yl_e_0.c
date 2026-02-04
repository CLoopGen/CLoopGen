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
for (j = 1; j < l; j++) {
    byp = (2 * j + 1) / x * by - bym;
    if (j % 2 == 0) {
        bym = by;
    } else {
        bym = byp;
    }
    by = byp;
}
}
