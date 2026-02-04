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
        uint16_t *n1 = nptr + i;
        uint16_t *o1 = optr + i;
        if (n1 + 1 >= nptr + w) break;

        int64_t t1 = (((*n1) - o1[os]) << 2) + n1[ns << 1] - o1[-os];
        tdif += t1 * t1;
        int64_t t2 = (((*o1) - n1[ns]) << 2) + o1[os << 1] - n1[-ns];
        bdif += t2 * t2;

        n1++; o1++;
        t1 = (((*n1) - o1[os]) << 2) + n1[ns << 1] - o1[-os];
        tdif += t1 * t1;
        t2 = (((*o1) - n1[ns]) << 2) + o1[os << 1] - n1[-ns];
        bdif += t2 * t2;
    }
    // Update nptr and optr to reflect advancement
    nptr += w;
    optr += w;
}
