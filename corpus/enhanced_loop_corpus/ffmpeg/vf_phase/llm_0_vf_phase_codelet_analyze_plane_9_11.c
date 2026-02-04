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



void loop(){
    for (rend = nptr + w; nptr < rend; nptr++, optr++) {
        int64_t temp_nptr_ns = *(nptr) - nptr[ns];
        int64_t temp_nptr_2ns = nptr[(ns) << 1];
        int64_t temp_nptr_neg_ns = nptr[-ns];
        pdif += ((t = (temp_nptr_ns << 2) + temp_nptr_2ns - temp_nptr_neg_ns), t * t);

        int64_t temp_optr_os = *(optr) - optr[os];
        int64_t temp_nptr_2ns_copy = nptr[(ns) << 1]; // reused from above
        int64_t temp_optr_neg_os = optr[-os];
        bdif += ((t = (temp_optr_os << 2) + temp_nptr_2ns_copy - temp_optr_neg_os), t * t);
    }
}
