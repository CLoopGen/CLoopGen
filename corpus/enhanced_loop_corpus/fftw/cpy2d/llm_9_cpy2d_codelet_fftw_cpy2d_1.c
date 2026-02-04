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
extern INT i0;
extern INT i1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i1 = 0; i1 < n1; i1 += 2) // Stride-2 outer loop to reduce trip count
        for (i0 = 0; i0 < n0; i0 += 2) { // Stride-2 inner loop
            // Process a 2x2 block to maintain data coverage
            *(double *)&O[i0 * os0 + i1 * os1] = *(double *)&I[i0 * is0 + i1 * is1];
            if (i0 + 1 < n0)
                *(double *)&O[(i0+1) * os0 + i1 * os1] = *(double *)&I[(i0+1) * is0 + i1 * is1];
            if (i1 + 1 < n1)
                *(double *)&O[i0 * os0 + (i1+1) * os1] = *(double *)&I[i0 * is0 + (i1+1) * is1];
            if (i0 + 1 < n0 && i1 + 1 < n1)
                *(double *)&O[(i0+1) * os0 + (i1+1) * os1] = *(double *)&I[(i0+1) * is0 + (i1+1) * is1];
        }
}
