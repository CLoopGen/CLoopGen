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



void loop() {
    // Variant 2: Consecutive array access using local pointers with reversed traversal
    // Access arrays from the end to the beginning to test different cache behavior
    // Uses pointer arithmetic starting from the last valid index down to nptr origin
    uint16_t *start_nptr = nptr;
    uint16_t *start_optr = optr;
    nptr = start_nptr + w - 1;
    optr = start_optr + w - 1;
    rend = start_nptr - 1;

    for (; nptr > rend; nptr--, optr--) {
        pdif += ((t) = ((*(nptr) - (nptr)[ns]) << 2) + (nptr)[(ns) << 1] - (nptr)[-(ns)], (t) * (t));
        bdif += ((t) = ((*(optr) - (nptr)[ns]) << 2) + (optr)[(os) << 1] - (nptr)[-(ns)], (t) * (t));
    }

    // Restore original pointers if needed by caller (though not strictly required per problem)
    nptr = start_nptr;
    optr = start_optr;
}
