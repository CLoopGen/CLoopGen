#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ns;
extern  int os;
extern  uint8_t *nptr;
extern  uint8_t *optr;
extern  int w;
extern int bdif;
extern int pdif;
extern int t;
extern  uint8_t *rend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with stride equal to ns (simulating block-based traversal)
    // Instead of sequential increment, advance by a fixed stride related to ns
    int stride = (ns > 0) ? ns : 1;
    rend = nptr + w;
    for (int i = 0; nptr + i < rend; i += stride) {
        uint8_t *n_addr = nptr + i;
        uint8_t *o_addr = optr + i;

        // Only process if within bounds for required offsets: -ns, ns, 2*ns
        if (n_addr - nptr >= ns && n_addr + (ns << 1) < w) {
            t = ((*n_addr - n_addr[ns]) << 2) + n_addr[(ns) << 1] - n_addr[-(ns)];
            pdif += t * t;

            t = ((*o_addr - n_addr[ns]) << 2) + o_addr[(os) << 1] - n_addr[-(ns)];
            bdif += t * t;
        }
    }

    // Final pass over any leftover elements not covered by striding
    for (; nptr < rend; nptr++, optr++) {
        t = ((*(nptr) - (nptr)[ns]) << 2) + (nptr)[(ns) << 1] - (nptr)[-(ns)];
        pdif += t * t;
        t = ((*(optr) - (nptr)[ns]) << 2) + (optr)[(os) << 1] - (nptr)[-(ns)];
        bdif += t * t;
    }
}
