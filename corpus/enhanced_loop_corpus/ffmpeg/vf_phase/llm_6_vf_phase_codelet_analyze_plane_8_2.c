#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ns;
extern  int os;
extern  uint8_t *nptr;
extern  uint8_t *optr;
extern  int w;
extern int bdif;
extern int pdif;
extern int t;
extern  uint8_t *rend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *nptr_local = nptr;
    uint8_t *optr_local = optr;
    int pdif_local = pdif;
    int bdif_local = bdif;
    for (rend = nptr_local + w; nptr_local < rend; nptr_local++, optr_local++) {
        int t_n = ((*(nptr_local) - nptr_local[ns]) << 2) + nptr_local[(ns) << 1] - nptr_local[-(ns)];
        int t_b = ((*(optr_local) - nptr_local[ns]) << 2) + optr_local[(os) << 1] - nptr_local[-(ns)];
        pdif_local += t_n * t_n;
        bdif_local += t_b * t_b;
    }
    pdif = pdif_local;
    bdif = bdif_local;
    nptr = nptr_local;
    optr = optr_local;
}
