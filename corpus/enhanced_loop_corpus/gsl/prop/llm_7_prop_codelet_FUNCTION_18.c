#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern  size_t size2;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int64_t* buffer = (int64_t*) malloc(size2 * sizeof(int64_t));
    if (!buffer) return;

    for (i = 0; i < size1; i++) {
        // Remove loop-carried dependencies by making inner loop fully independent
        for (j = 0; j < size2; j++) {
            buffer[j] = (i + 1) * (j + 1); // Write without depending on prior writes to other elements (no WAR/WAW)
        }
        // Independent computation using buffer, no carry-over between outer loop iterations
        buffer[0] = buffer[size2 - 1] + 1; // Break potential independence with a single update, but still no loop-carried dep
    }

    free(buffer);
}
