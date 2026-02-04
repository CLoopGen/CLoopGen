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
        int64_t temp_nptr_ns = nptr[ns];
        int64_t temp_nptr_neg_ns = nptr[-ns];
        int64_t temp_optr_os_shift = optr[os << 1];
        
        pdif += ((t) = ((*(nptr) - temp_nptr_ns) << 2) + nptr[(ns) << 1] - temp_nptr_neg_ns, (t) * (t));
        bdif += ((t) = ((*(optr) - temp_nptr_ns) << 2) + temp_optr_os_shift - temp_nptr_neg_ns, (t) * (t));
    }
}
