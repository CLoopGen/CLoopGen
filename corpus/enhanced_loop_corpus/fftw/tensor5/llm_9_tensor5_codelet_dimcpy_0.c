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
    for (i = 0; i < rnk * 2; i += 2) {
        dst[i/2] = src[i/2];
    }
}
