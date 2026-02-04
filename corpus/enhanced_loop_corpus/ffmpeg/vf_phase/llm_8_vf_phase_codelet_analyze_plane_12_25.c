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
for (rend = nptr + w; nptr < rend; nptr++, optr++) {
    int64_t diff1 = (*(nptr) - (nptr)[ns]);
    int64_t diff2 = (nptr)[(ns) << 1] - (nptr)[-ns];
    pdif += (diff1 << 2) + diff2;

    int64_t diff3 = (*(optr) - (nptr)[ns]);
    int64_t diff4 = (optr)[(os) << 1] - (nptr)[-ns];
    tdif += (diff3 << 2) + diff4;
}
}
