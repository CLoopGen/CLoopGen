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
    // Variant 2: Strided memory access with fixed step size (stride of 2)
    // We modify the access pattern to process every second element in a strided manner
    // This simulates scenarios with non-unit stride access, potentially modeling subsampled image rows or decimated signals

    int stride = 2;
    int limit = w / stride;

    for (int i = 0; i < limit; i++) {
        uint16_t *n_curr = nptr + i * stride;
        uint16_t *o_curr = optr + i * stride;

        int bdif_val = ((t) = (((*n_curr) - o_curr[os]) << 2) + n_curr[(ns) << 1] - o_curr[-os], t * t);
        int tdif_val = ((t) = (((*o_curr) - n_curr[ns]) << 2) + o_curr[(os) << 1] - n_curr[-ns], t * t);

        bdif += bdif_val;
        tdif += tdif_val;
    }

    // Update global pointers if side effects are expected (optional, depending on usage context)
    // Here we assume nptr/optr should point past last accessed element
    nptr += limit * stride;
    optr += limit * stride;
}
