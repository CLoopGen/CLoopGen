#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *delta;
extern integer i__1;
extern integer j;
extern real eta;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = i__1; j >= 1; --j) {
        delta[j] -= eta;
        if (j > 1) {
            delta[j-1] = delta[j] - delta[j-1] + delta[j-1];
        }
    }
}
