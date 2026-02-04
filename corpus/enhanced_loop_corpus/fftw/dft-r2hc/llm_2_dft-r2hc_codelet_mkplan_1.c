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
    INT rnk = cld_vec->rnk;
    iodim *dims = cld_vec->dims;
    for (i = 0; i < rnk; ++i) {
        iodim dim = dims[i]; // Local copy to modify
        if (dim.is < 0) {
            INT nm1 = dim.n - 1;
            ishift -= nm1 * (-dim.is);
            oshift -= nm1 * (-dim.os);
            // Update through pointer after local computation
            ((iodim*)(&dims[i]))->is = -dim.is;
            ((iodim*)(&dims[i]))->os = -dim.os;
        }
    }
}
