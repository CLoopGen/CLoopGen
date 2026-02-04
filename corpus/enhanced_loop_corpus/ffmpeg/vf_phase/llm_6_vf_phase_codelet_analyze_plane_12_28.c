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
    uint16_t *nptr_local = nptr;
    uint16_t *optr_local = optr;
    int64_t tdif_local = 0;
    int64_t bdif_local = 0;
    uint16_t temp_n, temp_o;

    for (rend = nptr_local + w; nptr_local < rend; nptr_local++, optr_local++) {
        temp_n = *(nptr_local);
        temp_o = *(optr_local);

        int64_t t1 = ((temp_n - optr_local[os]) << 2) + nptr_local[(ns) << 1] - optr_local[-(os)];
        tdif_local += t1 * t1;

        int64_t t2 = ((temp_o - nptr_local[ns]) << 2) + optr_local[(os) << 1] - nptr_local[-(ns)];
        bdif_local += t2 * t2;
    }

    tdif += tdif_local;
    bdif += bdif_local;
}
