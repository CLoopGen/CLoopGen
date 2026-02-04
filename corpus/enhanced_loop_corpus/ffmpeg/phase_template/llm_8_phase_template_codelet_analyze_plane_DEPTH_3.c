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
    int64_t pdif_local = 0;
    int64_t bdif_local = 0;
    uint16_t *nptr_local = nptr;
    uint16_t *optr_local = optr;
    for (rend = nptr_local + w; nptr_local < rend; nptr_local++, optr_local++) {
        int t1 = (*(nptr_local) - nptr_local[ns]) << 2;
        int t2 = nptr_local[(ns) << 1] - nptr_local[-ns];
        int t_val = t1 + t2;
        pdif_local += t_val * t_val;

        int u1 = (*(nptr_local) - optr_local[os]) << 2;
        int u2 = nptr_local[(ns) << 1] - optr_local[-os];
        int u_val = u1 + u2;
        bdif_local += u_val * u_val;
    }
    pdif += pdif_local;
    bdif += bdif_local;
}
