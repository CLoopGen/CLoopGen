#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t dest_size1;
extern  size_t dest_size2;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < dest_size1; i++) {
        size_t j;
        size_t e1 = 0, e2 = 0;
        // Remove loop-carried dependencies: accumulate independently per outer loop iteration
        for (j = 0; j < dest_size2; j++) {
            // Eliminate intra-loop dependencies: e1 and e2 updated without inter-dependence
            e1 = j;      // No dependency on previous e1
            e2 = i + j;  // Only current values used — no WAW or WAR hazards
        }
        // Use e1 and e2 after the inner loop to maintain semantic relevance
        if (e1 == dest_size2 - 1) {
            e2 *= 2;
        }
    }
}
