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
    if (w > 0) {
        int chunk = (w + 3) / 4;
        for (int i = 0; i < 4; i++) {
            uint16_t* start_n = nptr + i * chunk;
            uint16_t* start_o = optr + i * chunk;
            uint16_t* end_n = nptr + (i + 1) * chunk;
            if (start_n >= rend) break;
            if (end_n > rend) end_n = rend;

            for (nptr = start_n, optr = start_o; nptr < end_n; nptr++, optr++) {
                pdif += ((t) = ((*(nptr) - (nptr)[ns]) << 2) + (nptr)[(ns) << 1] - (nptr)[-(ns)], (t) * (t));
                bdif += ((t) = ((*(nptr) - (optr)[os]) << 2) + (nptr)[(ns) << 1] - (optr)[-(os)], (t) * (t));
                tdif += ((t) = ((*(optr) - (nptr)[ns]) << 2) + (optr)[(os) << 1] - (nptr)[-(ns)], (t) * (t));
            }
        }
    }
}
