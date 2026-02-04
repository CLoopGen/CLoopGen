#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ns;
extern  int os;
extern  uint16_t *nptr;
extern  uint16_t *optr;
extern  int w;
extern int64_t tdif;
extern int64_t pdif;
extern int t;
extern  uint16_t *rend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t *nptr_local = nptr;
    uint16_t *optr_local = optr;
    int64_t pdif_local = pdif;
    int64_t tdif_local = tdif;
    for (uint16_t *rend_local = nptr_local + w; nptr_local < rend_local; nptr_local++, optr_local++) {
        int t_n = (*(nptr_local) - nptr_local[ns]) << 2;
        t_n += nptr_local[(ns) << 1] - nptr_local[-ns];
        pdif_local += t_n * t_n;

        int t_o = (*(optr_local) - nptr_local[ns]) << 2;
        t_o += optr_local[(os) << 1] - nptr_local[-ns];
        tdif_local += t_o * t_o;
    }
    pdif = pdif_local;
    tdif = tdif_local;
    nptr = nptr_local;
    optr = optr_local;
}
