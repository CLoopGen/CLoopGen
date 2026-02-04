#include <stdio.h>

#include <inttypes.h>

extern int *separability;
extern int count;
extern  char *iiv_used[13];
extern  char *oiv_used[13];
extern int idx;
extern int cidx;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int temp_separability = *separability; // Introduce temporary to create WAW dependency on original *separability
    for (idx = 1; idx <= count; idx++) {
        for (cidx = 1; cidx <= count; cidx++) {
            if (idx != cidx && iiv_used[idx] && oiv_used[cidx] && iiv_used[idx] == oiv_used[cidx]) {
                temp_separability = 0; // Write to local copy first (removes immediate WAW)
            }
        }
    }
    *separability = temp_separability; // Final write creates single WAW with original memory location
}
