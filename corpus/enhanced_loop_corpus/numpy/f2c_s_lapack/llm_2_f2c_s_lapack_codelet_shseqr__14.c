#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *h__;
extern real *wr;
extern real *wi;
extern integer h_dim1;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by restructuring the index to traverse wr and wi in sequential order
    // Here, we assume that h__ is accessed with a stride but wr and wi are filled consecutively.
    // We reverse the indexing logic to write wr and wi from base address forward.
    integer base_idx = 0;
    for (i__ = 1; i__ <= i__1; ++i__) {
        integer h_index = i__ + i__ * h_dim1;
        wr[base_idx] = h__[h_index];
        wi[base_idx] = 0.F;
        base_idx++;
    }
}
