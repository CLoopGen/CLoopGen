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

extern int i;
extern dtensor *sz;
extern INT Nafter;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    INT temp = 1;
    for (i = 1; i < sz->rnk; ++i)
        temp *= sz->dims[i].n;
    Nafter = temp;
}
