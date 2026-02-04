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
    int64_t local_tdif = 0;
    int64_t local_bdif = 0;
    uint16_t *nptr_local = nptr;
    uint16_t *optr_local = optr;
    for (rend = nptr_local + w; nptr_local < rend; nptr_local++, optr_local++) {
        int t1 = ((*(nptr_local) - optr_local[os]) << 2) + nptr_local[(ns) << 1] - optr_local[-(os)];
        int t2 = ((*(optr_local) - nptr_local[ns]) << 2) + optr_local[(os) << 1] - nptr_local[-(ns)];
        local_tdif += t1 * t1;
        local_bdif += t2 * t2;
    }
    tdif += local_tdif;
    bdif += local_bdif;
}
