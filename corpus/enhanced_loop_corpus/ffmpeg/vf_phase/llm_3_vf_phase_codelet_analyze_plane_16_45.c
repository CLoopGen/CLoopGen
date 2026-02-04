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
    // Variant 2: Strided memory access with increased stride factor to simulate sparse traversal
    int stride_n = ns * 2;
    int stride_o = os * 2;
    int half_w = w / 2;  // Adjust iteration count due to larger stride
    uint16_t *n_end = nptr + half_w * stride_n;
    for (; nptr < n_end; nptr += stride_n, optr += stride_o) {
        bdif += ((t) = ((*(nptr) - (optr)[stride_o]) << 2) +
                      (nptr)[stride_n] - (optr)[-stride_o],
                      (t) * (t));
        tdif += ((t) = ((*(optr) - (nptr)[stride_n]) << 2) +
                      (optr)[stride_o] - (nptr)[-stride_n],
                      (t) * (t));
    }
}
