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
    int tdif_local = 0;
    int bdif_local = 0;
    int t_local;

    for (rend = nptr_local + w; nptr_local < rend; nptr_local++, optr_local++) {
        int nval = *nptr_local;
        int oval = optr_local[os];
        int n_shifted = nptr_local[ns << 1];
        int o_neg = optr_local[-os];

        t_local = ((nval - oval) << 2) + n_shifted - o_neg;
        tdif_local += t_local * t_local;

        t_local = ((*(optr_local) - nptr_local[ns]) << 2) + optr_local[(os) << 1] - nptr_local[-ns];
        bdif_local += t_local * t_local;
    }

    tdif += tdif_local;
    bdif += bdif_local;
}
