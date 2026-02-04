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
    uint16_t *nptr_local = nptr;
    uint16_t *optr_local = optr;
    int64_t pdif_local = 0;
    int64_t tdif_local = 0;
    int64_t bdif_local = 0;
    int t_local;

    for (rend = nptr_local + w; nptr_local < rend; nptr_local++, optr_local++) {
        t_local = ((*(nptr_local) - nptr_local[ns]) << 2) + nptr_local[(ns) << 1] - nptr_local[-ns];
        pdif_local += t_local * t_local;

        t_local = ((*(nptr_local) - optr_local[os]) << 2) + nptr_local[(ns) << 1] - optr_local[-os];
        tdif_local += t_local * t_local;

        t_local = ((*(optr_local) - nptr_local[ns]) << 2) + optr_local[(os) << 1] - nptr_local[-ns];
        bdif_local += t_local * t_local;
    }

    pdif += pdif_local;
    tdif += tdif_local;
    bdif += bdif_local;
}
