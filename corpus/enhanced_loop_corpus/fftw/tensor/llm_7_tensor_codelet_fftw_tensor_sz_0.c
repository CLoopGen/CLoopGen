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
    n = (sz->rnk > 0) ? sz->dims[0].n : 1;
    for (i = 1; i < sz->rnk; ++i)
        n = n * sz->dims[i].n + sz->dims[i-1].n;
}
