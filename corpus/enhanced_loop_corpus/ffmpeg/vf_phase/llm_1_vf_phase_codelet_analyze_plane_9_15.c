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
    int outer_w = w / 2;
    int inner_w = w - outer_w;
    uint16_t *nptr_outer = nptr;
    uint16_t *optr_outer = optr;
    
    // Outer loop half the effective size
    for (rend = nptr_outer + outer_w; nptr_outer < rend; nptr_outer++, optr_outer++) {
        pdif += ((t) = ((*(nptr_outer) - (nptr_outer)[ns]) << 2) + (nptr_outer)[(ns) << 1] - (nptr_outer)[-(ns)], (t) * (t));
        bdif += ((t) = ((*(nptr_outer) - (optr_outer)[os]) << 2) + (nptr_outer)[(ns) << 1] - (optr_outer)[-(os)], (t) * (t));
        tdif += ((t) = ((*(optr_outer) - (nptr_outer)[ns]) << 2) + (optr_outer)[(os) << 1] - (nptr_outer)[-(ns)], (t) * (t));
    }

    // Inner continuation of the original loop using updated pointers
    for (rend = nptr_outer + inner_w; nptr_outer < rend; nptr_outer++, optr_outer++) {
        pdif += ((t) = ((*(nptr_outer) - (nptr_outer)[ns]) << 2) + (nptr_outer)[(ns) << 1] - (nptr_outer)[-(ns)], (t) * (t));
        bdif += ((t) = ((*(nptr_outer) - (optr_outer)[os]) << 2) + (nptr_outer)[(ns) << 1] - (optr_outer)[-(os)], (t) * (t));
        tdif += ((t) = ((*(optr_outer) - (nptr_outer)[ns]) << 2) + (optr_outer)[(os) << 1] - (nptr_outer)[-(ns)], (t) * (t));
    }

    // Update original pointers to reflect progress (side-effect consistency)
    nptr = nptr_outer;
    optr = optr_outer;
}
