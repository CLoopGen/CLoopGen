#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

typedef int integer;

extern singlecomplex *y;
extern integer *incy;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access via Index Array
    // Use an auxiliary array of indices to perform indirect addressing
    // Simulate precomputed index lookup (e.g., gathered from another computation)
    static integer* index_map = NULL;
    if (index_map == NULL) {
        // Simulate dynamic allocation; in real use, this could be passed or precomputed
        index_map = (integer*)malloc(sizeof(integer) * (i__1 + 1));
        integer temp_iy = iy;
        for (integer j = 1; j <= i__1; ++j) {
            index_map[j] = temp_iy;
            temp_iy += *incy;
        }
    }

    for (i__ = 1; i__ <= i__1; ++i__) {
        integer mapped_index = index_map[i__];
        y[mapped_index].r = 0.F;
        y[mapped_index].i = 0.F;
    }
}
