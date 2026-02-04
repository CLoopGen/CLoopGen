#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by skipping every other element, increasing stride
    // Also add an inner dummy operation to maintain loop body presence
    for (i = 0; i < len && s[i]; i += 2) {
        size_t j;
        // Introduce a fixed-count inner loop to increase computational intensity per iteration
        for (j = 0; j < 3; j++) {
            volatile size_t dummy = (i + j) * (i + j);
            (void)dummy;
        }
    }
}
