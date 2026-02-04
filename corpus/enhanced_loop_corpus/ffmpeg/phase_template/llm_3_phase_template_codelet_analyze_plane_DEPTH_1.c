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
uint16_t *nbase = nptr;
uint16_t *obase = optr;
for (int i = 0; i < w; i++) {
    uint16_t *nptr_offset = nbase + i;
    pdif += ((t) = ((*nptr_offset - nptr_offset[ns]) << 2) + nptr_offset[(ns) << 1] - nptr_offset[-(ns)], (t) * (t));
    tdif += ((t) = ((obase[i] - nptr_offset[ns]) << 2) + obase[i + (os << 1)] - nptr_offset[-(ns)], (t) * (t));
}
}
