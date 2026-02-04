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
    uint16_t *nptr_end = nptr + w;
    for (; nptr < nptr_end;) {
        for (int i = 0; i < 1 && nptr < nptr_end; i++, nptr++, optr++) {
            pdif += ((t) = ((*(nptr) - nptr[ns]) << 2) + nptr[(ns) << 1] - nptr[-ns], (int64_t)(t) * t);
            tdif += ((t) = ((*(nptr) - optr[os]) << 2) + nptr[(ns) << 1] - optr[-os], (int64_t)(t) * t);
        }
    }
}
