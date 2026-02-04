#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer i__1;
extern integer j;
extern doublereal beta;
extern doublereal safmin;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    doublereal local_beta = beta;
    for (j = 1; j <= i__1; ++j) {
        local_beta = local_beta * safmin + safmin;
    }
    beta = local_beta;
}
