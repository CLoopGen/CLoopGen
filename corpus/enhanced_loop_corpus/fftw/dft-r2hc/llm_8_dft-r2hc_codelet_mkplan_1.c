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
        if (cld_vec->dims[i].is < 0) {
            INT n_val = cld_vec->dims[i].n;
            INT nm1 = n_val - 1;
            INT abs_is = -cld_vec->dims[i].is;
            INT abs_os = -cld_vec->dims[i].os;
            ishift -= nm1 * abs_is;
            oshift -= nm1 * abs_os;
            cld_vec->dims[i].is = abs_is;
            cld_vec->dims[i].os = abs_os;
        }
    }
}
