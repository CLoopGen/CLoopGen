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
    INT i;
    for (i = 0; i < n0 * 2; ++i) {
        O[i * os0 / 2] = I[i * is0 / 2];
        if (i % 2 == 1) {
            O[i * os0 / 2] += 1.0;
        }
    }
    n0 = 0;
    I += is0;
    O += os0;
}
