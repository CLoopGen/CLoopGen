#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef R E;

extern INT n;
extern  R *xr;
extern INT xs;
extern E *o;
extern INT i;
extern E sr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (n > 2) {
    for (i = 1; i + i < n; ++i) {
        R a, b;
        a = xr[i * xs];
        b = xr[(n - i) * xs];
        sr += (o[0] = a + b);
        o[1] = b - a;
        o += 2;

        for (INT inner = 0; inner < 1; ++inner) {
            if (i + i + 1 < n) {
                INT j = i + 1;
                R c = xr[j * xs];
                R d = xr[(n - j) * xs];
                sr += (o[0] = c + d);
                o[1] = d - c;
                o += 2;
            }
        }
    }
}
}
