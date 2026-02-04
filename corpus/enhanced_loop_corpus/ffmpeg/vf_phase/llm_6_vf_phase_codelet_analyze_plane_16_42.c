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
    int64_t pdif_local = 0;
    int64_t bdif_local = 0;
    uint16_t *rend_local = nptr_local + w;

    for (; nptr_local < rend_local; nptr_local++, optr_local++) {
        int t_n = (*(nptr_local) - nptr_local[ns]) << 2;
        int t_n_next = (nptr_local[(ns) << 1] - nptr_local[-ns]);
        int t_val_n = t_n + t_n_next;
        pdif_local += t_val_n * t_val_n;

        int t_o = (*(optr_local) - nptr_local[ns]) << 2;
        int t_o_next = (optr_local[(os) << 1] - nptr_local[-ns]);
        int t_val_o = t_o + t_o_next;
        bdif_local += t_val_o * t_val_o;
    }

    pdif += pdif_local;
    bdif += bdif_local;
}
