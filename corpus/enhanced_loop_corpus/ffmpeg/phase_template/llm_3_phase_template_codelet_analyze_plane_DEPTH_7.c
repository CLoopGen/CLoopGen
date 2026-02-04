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
    // Variant 2: Strided Memory Access with Increased Stride for Spatial Locality Exploration
    ptrdiff_t stride = 2;  // Stride factor to access every second element
    rend = nptr + w;
    for (ptrdiff_t offset = 0; nptr + offset < rend; offset += stride) {
        pdif += ((t) = (((nptr[offset]) - (nptr)[offset + ns]) << 2) + (nptr)[offset + (ns << 1)] - (nptr)[offset - ns], (t) * (t));
        bdif += ((t) = (((nptr[offset]) - (optr)[offset + os]) << 2) + (nptr)[offset + (ns << 1)] - (optr)[offset - os], (t) * (t));
        tdif += ((t) = (((optr[offset]) - (nptr)[offset + ns]) << 2) + (optr)[offset + (os << 1)] - (nptr)[offset - ns], (t) * (t));
    }
    // Handle remaining elements if w is not divisible by stride
    for (ptrdiff_t offset = (w / 2) * 2; nptr + offset < rend; offset++) {
        pdif += ((t) = (((nptr[offset]) - (nptr)[offset + ns]) << 2) + (nptr)[offset + (ns << 1)] - (nptr)[offset - ns], (t) * (t));
        bdif += ((t) = (((nptr[offset]) - (optr)[offset + os]) << 2) + (nptr)[offset + (ns << 1)] - (optr)[offset - os], (t) * (t));
        tdif += ((t) = (((optr[offset]) - (nptr)[offset + ns]) << 2) + (optr)[offset + (os << 1)] - (nptr)[offset - ns], (t) * (t));
    }
}
