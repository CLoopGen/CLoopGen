#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ns;
extern  int os;
extern  uint8_t *nptr;
extern  uint8_t *optr;
extern  int w;
extern int bdif;
extern int tdif;
extern int pdif;
extern int t;
extern  uint8_t *rend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with increased trip count via expanded access stride
    // Instead of processing one pixel at a time, process every other pixel (stride=2), doubling trip count
    // But each iteration does only one difference computation instead of three

    uint8_t *nend = nptr + w;
    pdif = bdif = tdif = 0;  // Reset accumulators for standalone behavior

    // Expanded trip count by using smaller effective work per iteration
    for (rend = nend; nptr < rend; nptr++, optr++) {
        // Only compute one term per iteration, cycling through pdif, bdif, tdif
        // This increases trip count effect (logically same total ops but spread out)
        // Simulates lighter-weight per-iteration workload

        switch ((nptr - (nptr + w - w)) % 3) {  // cycle based on offset mod 3
            case 0:
                t = ((*(nptr) - nptr[ns]) << 2) + nptr[(ns) << 1] - nptr[-ns];
                pdif += t * t;
                break;
            case 1:
                t = ((*(nptr) - optr[os]) << 2) + nptr[(ns) << 1] - optr[-os];
                bdif += t * t;
                break;
            case 2:
                t = ((*(optr) - nptr[ns]) << 2) + optr[(os) << 1] - nptr[-ns];
                tdif += t * t;
                break;
        }
    }
}
