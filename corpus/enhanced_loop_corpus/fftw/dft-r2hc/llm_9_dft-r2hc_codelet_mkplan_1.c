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
    int rnk = cld_vec->rnk;
    for (i = 0; i < rnk; i += 2) {
        int j = i + 1;
        iodim *dim_i = &cld_vec->dims[i];
        if (dim_i->is < 0) {
            INT nm1 = dim_i->n - 1;
            INT neg_is = -dim_i->is;
            INT neg_os = -dim_i->os;
            ishift -= nm1 * neg_is;
            oshift -= nm1 * neg_os;
            dim_i->is = neg_is;
            dim_i->os = neg_os;
        }
        if (j < rnk) {
            iodim *dim_j = &cld_vec->dims[j];
            if (dim_j->is < 0) {
                INT nm1 = dim_j->n - 1;
                INT neg_is = -dim_j->is;
                INT neg_os = -dim_j->os;
                ishift -= nm1 * neg_is;
                oshift -= nm1 * neg_os;
                dim_j->is = neg_is;
                dim_j->os = neg_os;
            }
        }
    }
}
