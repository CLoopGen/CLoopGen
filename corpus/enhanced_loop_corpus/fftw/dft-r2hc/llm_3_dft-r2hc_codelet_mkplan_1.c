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
    // Strided access: process dimensions in reverse order with stride of 1 (reverse traversal)
    for (i = cld_vec->rnk - 1; i >= 0; --i) {
        iodim *d = &cld_vec->dims[i];
        if (d->is < 0) {
            INT nm1 = d->n - 1;
            INT neg_is = -d->is;
            INT neg_os = -d->os;
            ishift -= nm1 * neg_is;
            oshift -= nm1 * neg_os;
            d->is = neg_is;
            d->os = neg_os;
        }
    }
}
