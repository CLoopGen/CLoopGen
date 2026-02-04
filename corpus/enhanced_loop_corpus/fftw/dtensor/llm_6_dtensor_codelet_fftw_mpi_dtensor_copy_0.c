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
    INT temp[sz->rnk];
    for (i = 0; i < sz->rnk; ++i) {
        temp[i] = sz->dims[i].n;
        x->dims[i].n = temp[i];
        x->dims[i].b[0] = sz->dims[i].b[0];
        x->dims[i].b[1] = sz->dims[i].b[1];
    }
}
