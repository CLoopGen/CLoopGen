#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef struct {
    INT n;
    INT b[2];
} ddim;

typedef struct {
    int rnk;
    ddim dims[1];
} dtensor;

extern  dtensor *sz;
extern dtensor *x;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (sz->rnk > 0) {
        i = 0;
        for (; i < sz->rnk; ++i)
            x->dims[i] = sz->dims[i];
    }
}
