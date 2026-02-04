#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ns;
extern  int os;
extern  uint8_t *nptr;
extern  uint8_t *optr;
extern  int w;
extern int tdif;
extern int pdif;
extern int t;
extern  uint8_t *rend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increased stride (stride = 4)
    const int stride = 4;
    uint8_t *nptr_end = nptr + (w / stride) * stride;

    for (rend = nptr + w; nptr < nptr_end; nptr += stride, optr += stride) {
        // Access every 4th element in a strided pattern
        for (int i = 0; i < stride; i++) {
            uint8_t *curr_n = nptr + i;
            uint8_t *curr_o = optr + i;

            pdif += ((t) = ((*(curr_n) - curr_n[ns]) << 2) + curr_n[(ns) << 1] - curr_n[-ns], (t) * (t));
            tdif += ((t) = ((*(curr_n) - curr_o[os]) << 2) + curr_n[(ns) << 1] - curr_o[-os], (t) * (t));
        }
    }

    // Handle leftover elements
    for (; nptr < rend; nptr++, optr++) {
        pdif += ((t) = ((*(nptr) - (nptr)[ns]) << 2) + (nptr)[(ns) << 1] - (nptr)[-(ns)], (t) * (t));
        tdif += ((t) = ((*(nptr) - (optr)[os]) << 2) + (nptr)[(ns) << 1] - (optr)[-(os)], (t) * (t));
    }
}
