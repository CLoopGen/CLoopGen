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

extern tensor *x;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (x->rnk > 0) {
        i = 0;
        for (; i < x->rnk; ++i)
            x->dims[i].is = x->dims[i].os;
    }
}
