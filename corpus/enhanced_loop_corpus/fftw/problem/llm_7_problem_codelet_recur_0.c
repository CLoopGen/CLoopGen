#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double R;

typedef ptrdiff_t INT;

typedef R E;

extern R *I;
extern INT i;
extern INT n;
extern INT is;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    INT stride = is * 2;
    for (i = 0; i < n; i += 2) {
        if (i + 1 < n) {
            I[i * is] = ((E)0.);           // Remove potential WAW by accessing non-overlapping elements
            I[(i + 1) * is] = ((E)1.);     // Independent assignment with different value to break WAW/RAW
        } else {
            I[i * is] = ((E)0.);
        }
    }
}
