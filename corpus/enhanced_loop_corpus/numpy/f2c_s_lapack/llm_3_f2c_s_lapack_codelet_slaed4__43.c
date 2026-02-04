#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *i__;
extern real *d__;
extern real *delta;
extern integer i__1;
extern integer j;
extern real midpt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access using an index mapping array
    integer *index_map = (integer*)malloc((i__1 + 1) * sizeof(integer));
    if (index_map == NULL) return; // handle allocation failure
    for (j = 1; j <= i__1; ++j) {
        index_map[j] = i__1 - j + 1; // reverse mapping
    }
    for (j = 1; j <= i__1; ++j) {
        int idx = index_map[j];
        delta[idx] = d__[idx] - d__[*i__] - midpt;
    }
    free(index_map);
}
