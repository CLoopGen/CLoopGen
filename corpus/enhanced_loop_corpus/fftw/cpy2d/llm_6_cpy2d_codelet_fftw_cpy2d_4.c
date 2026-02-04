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
extern INT n1;
extern INT is1;
extern INT os1;
extern INT vl;
extern INT i0;
extern INT i1;
extern INT v;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i1 = 0; i1 < n1; ++i1)
        for (i0 = 0; i0 < n0; ++i0)
            for (v = 0; v < vl; ++v) {
                INT idx_in = i0 * is0 + i1 * is1 + v;
                INT idx_out = i0 * os0 + i1 * os1 + v;
                R x0 = I[idx_in];
                O[idx_out] = x0;
                // Introduce a WAW dependency by writing an additional result to a shared location
                if (i0 == 0 && i1 == 0 && v == 0)
                    O[0] = O[0] + x0;  // Artificial WAW: write after write to O[0]
            }
}
