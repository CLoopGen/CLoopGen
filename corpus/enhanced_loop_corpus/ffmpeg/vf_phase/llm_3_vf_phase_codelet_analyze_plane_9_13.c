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
extern int t;
extern  uint16_t *rend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increased stride
    // Access every 2nd element to simulate strided pattern, effectively reducing iteration count
    // Maintains same computational structure but alters cache behavior and memory bandwidth usage
    const int stride = 2;
    const int effective_w = (w + stride - 1) / stride;
    for (int i = 0; i < effective_w; i++) {
        int nidx = i * stride;
        int oidx = i * stride;
        bdif += ((t) = (((nptr[nidx]) - optr[oidx + os]) << 2) + 
                        nptr[nidx + (ns << 1)] - optr[oidx - os], (t) * (t));
        tdif += ((t) = (((optr[oidx]) - nptr[nidx + ns]) << 2) + 
                        optr[oidx + (os << 1)] - nptr[nidx - ns], (t) * (t));
    }
}
