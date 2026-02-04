#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef R E;

extern INT i;
extern INT nb;
extern R *b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (INT step = 0; i + step < nb; ++step) {
    INT j = i + step;
    b[2 * j] = ((E)0.);
    b[2 * j + 1] = ((E)0.);
    if (step + 1 < nb - i) {
        j = i + step + 1;
        b[2 * j] = ((E)0.);
        b[2 * j + 1] = ((E)0.);
        ++step;
    }
}
i += (nb - i);
}
