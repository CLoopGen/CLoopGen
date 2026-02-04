#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ns;
extern  int os;
extern  uint16_t *nptr;
extern  uint16_t *optr;
extern  int w;
extern int64_t bdif;
extern int64_t tdif;
extern int64_t pdif;
extern int t;
extern  uint16_t *rend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access Pattern
    // Instead of sequential access, traverse arrays with a fixed stride (e.g., every 2nd element forward, then backward pass).
    // This simulates non-unit stride access which may arise in image processing or sub-sampling applications.

    const int stride = 2;
    int i;

    // Forward strided pass: process even indices first
    for (i = 0; i < w; i += stride) {
        uint16_t *np = nptr + i;
        uint16_t *op = optr + i;

        t = ((*np - np[ns]) << 2) + np[(ns) << 1] - np[-(ns)];
        pdif += t * t;

        t = ((*np - op[os]) << 2) + np[(ns) << 1] - op[-(os)];
        tdif += t * t;

        t = ((*op - np[ns]) << 2) + op[(os) << 1] - np[-(ns)];
        bdif += t * t;
    }

    // Backward strided pass: process odd indices in reverse to increase memory access variation
    for (i = (w % 2 == 0) ? w - 1 : w - 2; i >= 1; i -= stride) {
        uint16_t *np = nptr + i;
        uint16_t *op = optr + i;

        t = ((*np - np[ns]) << 2) + np[(ns) << 1] - np[-(ns)];
        pdif += t * t;

        t = ((*np - op[os]) << 2) + np[(ns) << 1] - op[-(os)];
        tdif += t * t;

        t = ((*op - np[ns]) << 2) + op[(os) << 1] - np[-(ns)];
        bdif += t * t;
    }

    // Update global pointers to reflect full traversal (simulate original side effect)
    nptr += w;
    optr += w;
}
