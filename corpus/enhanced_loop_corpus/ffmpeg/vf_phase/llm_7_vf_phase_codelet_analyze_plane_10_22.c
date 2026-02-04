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
    // Reverse iteration order to eliminate forward loop-carried dependencies
    // and change access pattern (from end to start)
    uint16_t *start_nptr = nptr;
    uint16_t *start_optr = optr;
    uint16_t *rend_ptr = nptr + w;

    // Adjust pointers to point just past the last element to be processed
    nptr = rend_ptr - 1;
    optr = start_optr + (w - 1);

    // Use negative stride via pointer decrement
    for (ptrdiff_t i = w; i > 0; i--, nptr--, optr--) {
        // Reorder computation sequence to alter data dependency chains
        int t_val;

        // Reuse same logic but reverse indexing: now accessing neighbors relative to current reversed position
        t_val = ((*(nptr) - nptr[ns]) << 2) + nptr[(ns) << 1] - nptr[-ns];
        pdif += t_val * t_val;

        t_val = ((*(nptr) - optr[os]) << 2) + nptr[(ns) << 1] - optr[-os];
        tdif += t_val * t_val;

        t_val = ((*(optr) - nptr[ns]) << 2) + optr[(os) << 1] - nptr[-ns];
        bdif += t_val * t_val;
    }

    // Restore original pointers if needed by semantics (though not strictly required per problem)
    nptr = start_nptr;
    optr = start_optr;
}
