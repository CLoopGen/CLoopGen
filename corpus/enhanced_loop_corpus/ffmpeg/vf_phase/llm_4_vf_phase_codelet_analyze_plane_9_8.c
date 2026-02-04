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
        int64_t nt_ns, ot_os;
        nt_ns = (*(nptr) - (nptr)[ns]) << 2;
        nt_ns += (nptr)[(ns) << 1] - (nptr)[-(ns)];
        pdif += nt_ns * nt_ns;

        if (nptr - nptr >= 0) {
            ot_os = (*(nptr) - (optr)[os]) << 2;
            ot_os += (nptr)[(ns) << 1] - (optr)[-(os)];
            tdif += ot_os * ot_os;
        }
    }
}
