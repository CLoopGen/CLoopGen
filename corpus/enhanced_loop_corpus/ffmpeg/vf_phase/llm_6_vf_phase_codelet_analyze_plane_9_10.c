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
    uint16_t *nptr_local = nptr;
    uint16_t *optr_local = optr;
    int64_t pdif_local = pdif;
    int64_t bdif_local = bdif;
    for (uint16_t *rend_local = nptr_local + w; nptr_local < rend_local; nptr_local++, optr_local++) {
        int t_n = ((*(nptr_local) - nptr_local[ns]) << 2) + nptr_local[(ns) << 1] - nptr_local[-ns];
        pdif_local += t_n * t_n;
        int t_b = ((*(optr_local) - nptr_local[ns]) << 2) + optr_local[(os) << 1] - nptr_local[-ns];
        bdif_local += t_b * t_b;
    }
    pdif = pdif_local;
    bdif = bdif_local;
    nptr = nptr_local;
    optr = optr_local;
}
