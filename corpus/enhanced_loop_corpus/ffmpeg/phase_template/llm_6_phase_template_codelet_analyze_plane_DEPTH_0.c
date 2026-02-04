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
    int64_t pdif_local = 0;
    int64_t tdif_local = 0;
    for (uint16_t *rend_local = nptr_local + w; nptr_local < rend_local; nptr_local++, optr_local++) {
        int t1 = (*(nptr_local) - nptr_local[ns]) << 2;
        int t2 = nptr_local[(ns) << 1] - nptr_local[-ns];
        int temp_p = t1 + t2;
        pdif_local += temp_p * temp_p;

        int u1 = (*(nptr_local) - optr_local[os]) << 2;
        int u2 = nptr_local[(ns) << 1] - optr_local[-os];
        int temp_t = u1 + u2;
        tdif_local += temp_t * temp_t;
    }
    pdif += pdif_local;
    tdif += tdif_local;
}
