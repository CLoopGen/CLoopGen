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
    uint16_t *n_base = nptr;
    uint16_t *o_base = optr;
    uint16_t *rend_local = n_base + w;

    int64_t pdif_local = 0;
    int64_t tdif_local = 0;

    for (int i = 0; i < w; i++) {
        uint16_t val_n = n_base[i];
        uint16_t val_optr = o_base[i];
        uint16_t n_ns = n_base[i + ns];
        uint16_t n_2ns = n_base[i + (ns << 1)];
        uint16_t n_neg_ns = n_base[i - ns];
        uint16_t o_2os = o_base[i + (os << 1)];

        int t1 = ((val_n - n_ns) << 2) + n_2ns - n_neg_ns;
        int t2 = ((val_optr - n_ns) << 2) + o_2os - n_neg_ns;

        pdif_local += t1 * t1;
        tdif_local += t2 * t2;
    }

    pdif += pdif_local;
    tdif += tdif_local;
}
