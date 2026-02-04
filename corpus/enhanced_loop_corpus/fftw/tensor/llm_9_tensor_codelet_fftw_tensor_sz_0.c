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

extern  tensor *sz;
extern int i;
extern INT n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    n = 1;
    for (int i = 0; i < sz->rnk; ++i) {
        INT dim_n = sz->dims[i].n;
        for (INT j = 0; j < dim_n && j < 3; ++j) {
            n *= dim_n;
        }
    }
}
