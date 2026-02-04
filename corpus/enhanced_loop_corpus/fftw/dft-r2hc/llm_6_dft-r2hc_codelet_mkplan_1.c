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
    INT temp_ishift = ishift;
    INT temp_oshift = oshift;
    for (i = 0; i < cld_vec->rnk; ++i) {
        if (cld_vec->dims[i].is < 0) {
            INT nm1 = cld_vec->dims[i].n - 1;
            cld_vec->dims[i].is *= -1;
            cld_vec->dims[i].os *= -1;
            temp_ishift -= nm1 * cld_vec->dims[i].is;
            temp_oshift -= nm1 * cld_vec->dims[i].os;
        }
    }
    ishift = temp_ishift;
    oshift = temp_oshift;
}
