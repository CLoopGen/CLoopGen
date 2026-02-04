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
for (i = 0; i < cld_vec->rnk; ++i) {
    INT is_val = cld_vec->dims[i].is;
    if (is_val >= 0) continue;
    INT nm1 = cld_vec->dims[i].n - 1;
    ishift -= nm1 * (-is_val);
    oshift -= nm1 * (-(cld_vec->dims[i].os));
    cld_vec->dims[i].is = -is_val;
    cld_vec->dims[i].os = -(cld_vec->dims[i].os);
}
}
