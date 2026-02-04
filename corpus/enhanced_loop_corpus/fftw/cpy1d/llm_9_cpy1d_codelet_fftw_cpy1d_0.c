#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double R;

typedef ptrdiff_t INT;

extern R *I;
extern R *O;
extern INT n0;
extern INT is0;
extern INT os0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    INT stride = 2;
    for (; n0 > 0; n0 -= stride, I += is0 * stride, O += os0 * stride) {
        *O = *I;
        *(O + os0) = *(I + is0);
    }
}
