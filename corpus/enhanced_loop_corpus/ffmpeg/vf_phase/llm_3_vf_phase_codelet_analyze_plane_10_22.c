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
    // Variant 2: Strided memory access with increased stride (every 4th element)
    // This variant changes the access pattern to a strided one, stepping by 4 each iteration,
    // which may be useful for data-level parallelism or when working with interleaved data formats.

    const int stride = 4;
    uint16_t *base_n = nptr;
    uint16_t *base_o = optr;
    int limit = (w / stride) * stride;  // Round down to nearest multiple of stride

    for (int i = 0; i < limit; i += stride) {
        uint16_t *nptr_local = base_n + i;
        uint16_t *optr_local = base_o + i;

        // Access elements with fixed offset using stride
        pdif += ((t) = ((*(nptr_local) - nptr_local[ns]) << 2) + nptr_local[(ns) << 1] - nptr_local[-ns], (t) * (t));
        tdif += ((t) = ((*(nptr_local) - optr_local[os]) << 2) + nptr_local[(ns) << 1] - optr_local[-os], (t) * (t));
        bdif += ((t) = ((*(optr_local) - nptr_local[ns]) << 2) + optr_local[(os) << 1] - nptr_local[-ns], (t) * (t));
    }

    // Finalize pointers after loop (simulate original side effects)
    nptr = base_n + w;
    optr = base_o + w;
}
