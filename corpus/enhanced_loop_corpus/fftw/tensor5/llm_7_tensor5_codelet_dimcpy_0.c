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

extern iodim *dst;
extern  iodim *src;
extern int rnk;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < rnk; ++i) {
        dst[i].n = src[i].n;
        dst[i].is = src[i].is;
        dst[i].os = src[i].os;
        // Introduce a WAW dependency across iterations by conditionally overwriting
        if (i > 0) {
            dst[i-1].os = dst[i].os; // WAW on dst[i-1], carried across iterations
        }
    }
}
