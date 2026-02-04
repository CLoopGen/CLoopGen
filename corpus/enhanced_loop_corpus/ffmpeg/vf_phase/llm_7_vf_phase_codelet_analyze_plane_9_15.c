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
extern int64_t pdif;
extern int t;
extern  uint16_t *rend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t *nptr_local = nptr;
    uint16_t *optr_local = optr;
    int64_t temp_sum = 0;
    int t1, t2, t3;
    rend = nptr_local + w;
    for (int i = 0; i < w; i++) {
        t1 = ((nptr_local[i] - nptr_local[i + ns]) << 2) + nptr_local[i + (ns << 1)] - nptr_local[i - ns];
        t2 = ((nptr_local[i] - optr_local[i + os]) << 2) + nptr_local[i + (ns << 1)] - optr_local[i - os];
        t3 = ((optr_local[i] - nptr_local[i + ns]) << 2) + optr_local[i + (os << 1)] - nptr_local[i - ns];
        temp_sum += t1 * t1 + t2 * t2 + t3 * t3;
    }
    pdif += temp_sum / 3;
    bdif += temp_sum / 3;
    tdif += temp_sum / 3;
}
