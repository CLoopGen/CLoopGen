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
    iodim* dim = &cld_vec->dims[i];
    INT n = dim->n;
    INT is = dim->is;
    INT os = dim->os;
    if (is < 0 && n > 0) {
        INT nm1 = n - 1;
        ishift -= nm1 * (-is);
        oshift -= nm1 * (-os);
        dim->is = -is;
        dim->os = -os;
    } else {
        dim->is = is;
        dim->os = os;
    }
}
}
