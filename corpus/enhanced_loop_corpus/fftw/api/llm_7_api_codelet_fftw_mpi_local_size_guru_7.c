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
    INT product = Nafter;
    for (i = 2; i < sz->rnk; ++i) {
        product *= sz->dims[i].n;
        sz->dims[i].b[0] = product; // Introduce WAW and WAR dependency via dummy write
    }
    Nafter = product;
}
