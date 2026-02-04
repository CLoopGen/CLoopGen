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



void loop() {
    // Variant 1: Consecutive memory access with precomputed pointers and unrolled stride
    uint16_t *n_end = nptr + w;
    uint16_t *o_current = optr;

    for (; nptr < n_end; nptr += 2, o_current += 2) {
        int64_t t1, t2;

        // First iteration of unrolled loop
        if (nptr + 0 < n_end - 1 || nptr + 0 == n_end - 1) {
            uint16_t n_val = nptr[0];
            t1 = ((n_val - nptr[ns]) << 2) + nptr[ns << 1] - nptr[-ns];
            pdif += t1 * t1;

            t2 = ((o_current[0] - nptr[ns]) << 2) + o_current[os << 1] - nptr[-ns];
            tdif += t2 * t2;
        }

        // Second iteration of unrolled loop (if valid)
        if (nptr + 1 < n_end) {
            uint16_t n_val_next = nptr[1];
            t1 = ((n_val_next - nptr[1 + ns]) << 2) + nptr[(1 + ns) << 1] - nptr[1 - ns];
            pdif += t1 * t1;

            t2 = ((o_current[1] - nptr[1 + ns]) << 2) + o_current[os << 1] - nptr[1 - ns];
            tdif += t2 * t2;
        }
    }
}
