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
    uint16_t *nptr_base = nptr;
    uint16_t *optr_base = optr;
    int i;
    for (i = 0; i < w; i++) {
        int idx = i;
        int nidx_forward = idx + ns;
        int oidx_forward = idx + os;
        int nidx_backward = idx - ns;
        int oidx_backward = idx - os;

        int t1 = ((nptr_base[idx] - optr_base[oidx_forward]) << 2) + 
                 nptr_base[nidx_forward] - optr_base[oidx_backward];
        tdif += t1 * t1;

        int t2 = ((optr_base[idx] - nptr_base[nidx_forward]) << 2) + 
                 optr_base[oidx_forward] - nptr_base[nidx_backward];
        bdif += t2 * t2;
    }
}
