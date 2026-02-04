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
if (l > 1) {
    for (j = 1; j < l; j++) {
        for (int k = j; k < j + 1; k++) {
            byp = (2 * j + 1) / x * by - bym;
            bym = by;
            by = byp;
        }
    }
}
}
