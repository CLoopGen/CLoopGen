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
extern int64_t pdif;
extern int t;
extern  uint16_t *rend;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided memory access with step size defined by 'ns' and 'os'
    int stride = (ns > 1) ? ns : 1;
    int ostride = (os > 1) ? os : 1;
    int count = w / stride;  // Number of full strides we can take

    rend = nptr + count * stride;
    for (uint16_t *base = nptr; base < rend; base += stride, optr += ostride) {
        int t_val;

        // Access elements at strided positions
        pdif += ((t_val) = ((base[0] - base[ns]) << 2) + base[(ns) << 1] - base[-(ns)], (int64_t)t_val * t_val);
        bdif += ((t_val) = ((base[0] - optr[ostride]) << 2) + base[(ns) << 1] - optr[-(os)], (int64_t)t_val * t_val);
    }

    // Final cleanup pass for remaining elements using original pointer logic
    // This ensures no deviation from expected behavior on boundary
    for (rend = nptr + w; nptr < rend; nptr++, optr++) {
        pdif += ((t) = ((*(nptr) - (nptr)[ns]) << 2) + (nptr)[(ns) << 1] - (nptr)[-(ns)], (int64_t)t * t);
        bdif += ((t) = ((*(nptr) - (optr)[os]) << 2) + (nptr)[(ns) << 1] - (optr)[-(os)], (int64_t)t * t);
    }
}
