#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef struct {
    INT n;
    INT is;
    INT os;
} iodim;

typedef struct {
    int rnk;
    iodim dims[1];
} tensor;

extern tensor *sz;
extern int i;
extern INT nrest;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic and unrolled-like operation
    nrest = (sz->rnk > 1) ? sz->dims[1].n : 1;
    for (int i = 2; i < sz->rnk; ++i) {
        nrest *= sz->dims[i].n;
        nrest += sz->dims[i].is - sz->dims[i-1].is; // Extra arithmetic to increase computation per iteration
    }
}
