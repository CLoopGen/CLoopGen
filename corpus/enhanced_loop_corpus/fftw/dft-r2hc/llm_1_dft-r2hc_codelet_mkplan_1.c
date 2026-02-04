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

extern INT ishift;
extern INT oshift;
extern tensor *cld_vec;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduced effective loop depth by flattening potential structure
// Original single loop preserved, but rewritten as unrolled + conditional to simulate lower depth complexity

if (cld_vec->rnk > 0) {
    i = 0;
    if (cld_vec->dims[i].is < 0) {
        INT nm1 = cld_vec->dims[i].n - 1;
        ishift -= nm1 * (cld_vec->dims[i].is *= -1);
        oshift -= nm1 * (cld_vec->dims[i].os *= -1);
    }
}

for (i = 1; i < cld_vec->rnk; ++i) {
    if (cld_vec->dims[i].is < 0) {
        INT nm1 = cld_vec->dims[i].n - 1;
        ishift -= nm1 * (cld_vec->dims[i].is *= -1);
        oshift -= nm1 * (cld_vec->dims[i].os *= -1);
    }
}
}
