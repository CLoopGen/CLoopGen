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
for (i = rnk - 1; i > 0; --i) {
    x->dims[i - 1].n = n[i - 1];
    if (i % 2 == 0) {
        x->dims[i - 1].is = x->dims[i].is * niphys[i];
        x->dims[i - 1].os = x->dims[i].os * nophys[i];
    } else {
        x->dims[i - 1].is = x->dims[i].is;
        x->dims[i - 1].os = x->dims[i].os;
    }
}
}
