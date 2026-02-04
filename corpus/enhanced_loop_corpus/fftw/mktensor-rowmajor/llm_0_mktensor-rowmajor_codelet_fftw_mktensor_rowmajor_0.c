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

extern int rnk;
extern  int *n;
extern  int *niphys;
extern  int *nophys;
extern tensor *x;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (INT depth = 1; depth <= rnk - 1; ++depth) {
        for (i = rnk - 1; i >= depth; --i) {
            x->dims[i - 1].is = x->dims[i].is * niphys[i];
            x->dims[i - 1].os = x->dims[i].os * nophys[i];
            x->dims[i - 1].n = n[i - 1];
        }
    }
}
