#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double R;

typedef ptrdiff_t INT;

typedef R E;

extern R *I0;
extern R *I1;
extern INT i;
extern INT n;
extern INT is;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (INT outer = 0; outer < n - 1; outer += 2) {
    for (INT inner = 0; inner < 2; ++inner) {
        if (outer + inner < n - 1) {
            *(I0 + inner * is) = *(I1 + inner * is) = ((E)0.);
        }
    }
    I0 += 2 * is;
    I1 += 2 * is;
    outer += 1; // Compensate for stride since inner loop handles two elements
}
}
