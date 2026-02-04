#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer i__1;
extern integer j;
extern real beta;
extern real safmin;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    for (integer k = 0; k < 3; ++k) {
        for (integer m = 0; m < 2; ++m) {
            beta *= safmin;
        }
    }
}
}
