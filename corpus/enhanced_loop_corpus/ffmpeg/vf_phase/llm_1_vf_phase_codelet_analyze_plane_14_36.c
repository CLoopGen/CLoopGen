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
    for (int i = 0; i < w; i += 2) {
        uint16_t *nptr1 = nptr + i;
        uint16_t *optr1 = optr + i;
        if (nptr1 + 1 < nptr + w) {
            int64_t t1 = ((nptr1[0] - optr1[os]) << 2) + nptr1[ns << 1] - optr1[-os];
            int64_t t2 = ((optr1[0] - nptr1[ns]) << 2) + optr1[os << 1] - nptr1[-ns];
            tdif += t1 * t1;
            bdif += t2 * t2;

            t1 = ((nptr1[1] - optr1[os + 1]) << 2) + (nptr1 + 1)[ns << 1] - (optr1 + 1)[-os];
            t2 = ((optr1[1] - (nptr1 + 1)[ns]) << 2) + (optr1 + 1)[os << 1] - (nptr1 + 1)[-ns];
            tdif += t1 * t1;
            bdif += t2 * t2;
        } else {
            int64_t t1 = ((nptr1[0] - optr1[os]) << 2) + nptr1[ns << 1] - optr1[-os];
            int64_t t2 = ((optr1[0] - nptr1[ns]) << 2) + optr1[os << 1] - nptr1[-ns];
            tdif += t1 * t1;
            bdif += t2 * t2;
        }
    }
}
