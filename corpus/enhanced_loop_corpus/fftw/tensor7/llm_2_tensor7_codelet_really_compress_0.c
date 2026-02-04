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
extern int rnk;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = rnk = 0; i < sz->rnk; ++i) {
        const iodim* dim = &sz->dims[i]; // Use pointer to current dimension (consecutive access pattern)
        if (dim->n != 1)
            ++rnk;
    }
}
