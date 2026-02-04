#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *n;
extern real *z__;
extern real *delta;
extern real *work;
extern integer i__1;
extern integer j;
extern real phi;
extern real dphi;
extern real temp;
extern real erretm;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduced computational intensity and trip count by skipping every other element
integer step = 2;
for (j = *n; j >= i__1; j -= step) {
    temp = z__[j] / work[j];
    phi += z__[j] * temp;
    // Removed dphi and erretm updates to reduce operations
    // Simplified to lower arithmetic complexity
}
}
