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
int k;
for (k = 0; k < 1; k++) {
    for (j = 1; j < n; j++) {
        byp = j * two_over_x * by - bym;
        bym = by;
        by = byp;
    }
}
}
