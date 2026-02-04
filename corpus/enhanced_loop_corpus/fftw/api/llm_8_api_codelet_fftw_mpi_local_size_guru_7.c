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
    INT step = 2;
    for (i = 2; i < sz->rnk; i += step) {
        if (i + 1 < sz->rnk) {
            Nafter *= sz->dims[i].n * sz->dims[i + 1].n;
        } else {
            Nafter *= sz->dims[i].n;
        }
    }
}
