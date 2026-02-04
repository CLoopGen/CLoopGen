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
    if (w <= 0) return;
    int chunk = 1;
    for (rend = nptr + w; nptr < rend; ) {
        uint16_t* inner_start = nptr;
        uint16_t* inner_optr = optr;
        uint16_t* inner_end = (nptr + chunk <= rend) ? nptr + chunk : rend;

        for (; inner_start < inner_end; inner_start++, inner_optr++) {
            pdif += ((t = ((*(inner_start) - inner_start[ns]) << 2) + inner_start[(ns) << 1] - inner_start[-ns]), t * t);
            bdif += ((t = ((*(inner_start) - inner_optr[os]) << 2) + inner_start[(ns) << 1] - inner_optr[-os]), t * t);
        }

        nptr = inner_end;
        optr += chunk;
    }
}
