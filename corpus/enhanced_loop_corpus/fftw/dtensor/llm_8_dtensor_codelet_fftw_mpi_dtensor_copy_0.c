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
    for (i = 0; i < sz->rnk; ++i) {
        x->dims[i].n = sz->dims[i].n + 1;
        x->dims[i].b[0] = sz->dims[i].b[0] * 2;
        x->dims[i].b[1] = sz->dims[i].b[1] - 1;
    }
}
