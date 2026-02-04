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
extern int tdif;
extern int t;
extern  uint8_t *rend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *nptr_local = nptr;
    uint8_t *optr_local = optr;
    int bdif_local = bdif;
    int tdif_local = tdif;
    for (rend = nptr_local + w; nptr_local < rend; nptr_local++, optr_local++) {
        int t_n = (*(nptr_local) - optr_local[os]) << 2;
        int t_n_next = (nptr_local)[ns << 1] - optr_local[-os];
        bdif_local += ((t) = t_n + t_n_next, t * t);

        int t_o = (*(optr_local) - nptr_local[ns]) << 2;
        int t_o_next = (optr_local)[os << 1] - nptr_local[-ns];
        tdif_local += ((t) = t_o + t_o_next, t * t);
    }
    bdif = bdif_local;
    tdif = tdif_local;
    nptr = nptr_local;
    optr = optr_local;
}
