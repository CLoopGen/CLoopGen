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
    int i;
    for (i = 0; i < w; i += 2) {
        uint16_t *n1 = nptr, *o1 = optr;
        uint16_t *n2 = nptr + 1, *o2 = optr + 1;
        rend = nptr + w;

        if (n1 + 1 >= rend) {
            // Handle odd-sized tail
            pdif += ((t) = ((*(n1) - (n1)[ns]) << 2) + (n1)[(ns) << 1] - (n1)[-(ns)], (t) * (t));
            tdif += ((t) = ((*(n1) - (o1)[os]) << 2) + (n1)[(ns) << 1] - (o1)[-(os)], (t) * (t));
            bdif += ((t) = ((*(o1) - (n1)[ns]) << 2) + (o1)[(os) << 1] - (n1)[-(ns)], (t) * (t));
            break;
        }

        // Unrolled iteration with depth-1 nesting to simulate structural change
        {
            pdif += ((t) = ((*(n1) - (n1)[ns]) << 2) + (n1)[(ns) << 1] - (n1)[-(ns)], (t) * (t));
            tdif += ((t) = ((*(n1) - (o1)[os]) << 2) + (n1)[(ns) << 1] - (o1)[-(os)], (t) * (t));
            bdif += ((t) = ((*(o1) - (n1)[ns]) << 2) + (o1)[(os) << 1] - (n1)[-(ns)], (t) * (t));
        }
        {
            pdif += ((t) = ((*(n2) - (n2)[ns]) << 2) + (n2)[(ns) << 1] - (n2)[-(ns)], (t) * (t));
            tdif += ((t) = ((*(n2) - (o2)[os]) << 2) + (n2)[(ns) << 1] - (o2)[-(os)], (t) * (t));
            bdif += ((t) = ((*(o2) - (n2)[ns]) << 2) + (o2)[(os) << 1] - (n2)[-(ns)], (t) * (t));
        }

        nptr += 2;
        optr += 2;
    }
}
