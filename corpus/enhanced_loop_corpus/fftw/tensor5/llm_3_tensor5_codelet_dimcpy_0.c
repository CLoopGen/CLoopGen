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
    INT stride = 2;
    for (i = 0; i < rnk; i += stride) {
        if (i + 1 < rnk) {
            dst[i] = src[i];
            dst[i + 1] = src[i + 1];
        } else {
            dst[i] = src[i];
        }
    }
}
