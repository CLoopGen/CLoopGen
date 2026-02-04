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
    for (int i = 0; i < w; i += 2) {
        uint16_t *n1 = nptr + i;
        uint16_t *o1 = optr + i;
        if (n1 + 1 >= rend) break;
        int64_t t1 = ((n1[0] - n1[ns]) << 2) + n1[(ns) << 1] - n1[-ns];
        int64_t t2 = ((n1[0] - o1[os]) << 2) + n1[(ns) << 1] - o1[-os];
        pdif += t1 * t1;
        bdif += t2 * t2;

        int64_t t3 = ((n1[1] - (n1+1)[ns]) << 2) + (n1+1)[(ns) << 1] - (n1+1)[-ns];
        int64_t t4 = ((n1[1] - (o1+1)[os]) << 2) + (n1+1)[(ns) << 1] - (o1+1)[-os];
        pdif += t3 * t3;
        bdif += t4 * t4;
    }
    // Handle odd leftover element
    if (w % 2 == 1) {
        uint16_t *nptr_temp = nptr + w - 1;
        uint16_t *optr_temp = optr + w - 1;
        int64_t t1 = ((*nptr_temp - nptr_temp[ns]) << 2) + nptr_temp[(ns) << 1] - nptr_temp[-ns];
        int64_t t2 = ((*nptr_temp - optr_temp[os]) << 2) + nptr_temp[(ns) << 1] - optr_temp[-os];
        pdif += t1 * t1;
        bdif += t2 * t2;
    }
}
