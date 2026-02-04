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
    int64_t local_pdif = 0;
    int64_t local_bdif = 0;
    uint16_t *local_nptr = nptr;
    uint16_t *local_optr = optr;
    for (rend = local_nptr + w; local_nptr < rend; local_nptr++, local_optr++) {
        int t1 = ((*(local_nptr) - local_nptr[ns]) << 2) + local_nptr[(ns) << 1] - local_nptr[-(ns)];
        int t2 = ((*(local_nptr) - local_optr[os]) << 2) + local_nptr[(ns) << 1] - local_optr[-(os)];
        local_pdif += t1 * t1;
        local_bdif += t2 * t2;
    }
    pdif += local_pdif;
    bdif += local_bdif;
}
