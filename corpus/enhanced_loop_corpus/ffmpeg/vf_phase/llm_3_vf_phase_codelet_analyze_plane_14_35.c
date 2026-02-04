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
    // Variant 2: Consecutive Block Access with Pointer Offsets (Unrolled-like consecutive access)
    // Access memory in larger blocks with fixed offsets to simulate better spatial locality
    int block_size = 4;
    uint16_t *nbase, *obase;
    int i;

    for (nbase = nptr, obase = optr; nbase < nptr + w - block_size + 1; nbase += block_size, obase += block_size) {
        for (i = 0; i < block_size; i++) {
            uint16_t *ncurr = nbase + i;
            uint16_t *ocurr = obase + i;

            pdif += ((t) = ((*(ncurr) - ncurr[ns]) << 2) + ncurr[(ns) << 1] - ncurr[-(ns)], (t) * (t));
            bdif += ((t) = ((*(ncurr) - ocurr[os]) << 2) + ncurr[(ns) << 1] - ocurr[-(os)], (t) * (t));
        }
    }

    // Handle trailing elements
    for (; nbase < nptr + w; nbase++, obase++) {
        pdif += ((t) = ((*(nbase) - nbase[ns]) << 2) + nbase[(ns) << 1] - nbase[-(ns)], (t) * (t));
        bdif += ((t) = ((*(nbase) - obase[os]) << 2) + nbase[(ns) << 1] - obase[-(os)], (t) * (t));
    }
}
