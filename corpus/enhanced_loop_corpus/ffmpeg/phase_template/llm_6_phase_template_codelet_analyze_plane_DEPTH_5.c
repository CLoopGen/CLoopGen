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
    int64_t bdif_local = 0;
    int64_t tdif_local = 0;
    uint16_t *rend_local = nptr_local + w;
    int t_local;

    for (; nptr_local < rend_local; nptr_local++, optr_local++) {
        int16_t diff_n_optr = (int16_t)(*nptr_local) - (int16_t)(optr_local[os]);
        int16_t n_shifted = diff_n_optr << 2;
        int16_t n_plus_ns = (int16_t)(nptr_local[ns << 1]);
        int16_t o_neg_os = (int16_t)(optr_local[-os]);
        t_local = n_shifted + n_plus_ns - o_neg_os;
        bdif_local += t_local * t_local;

        int16_t diff_o_nptr = (int16_t)(*optr_local) - (int16_t)(nptr_local[ns]);
        int16_t o_shifted = diff_o_nptr << 2;
        int16_t o_plus_os = (int16_t)(optr_local[os << 1]);
        int16_t n_neg_ns = (int16_t)(nptr_local[-ns]);
        t_local = o_shifted + o_plus_os - n_neg_ns;
        tdif_local += t_local * t_local;
    }

    bdif += bdif_local;
    tdif += tdif_local;
}
