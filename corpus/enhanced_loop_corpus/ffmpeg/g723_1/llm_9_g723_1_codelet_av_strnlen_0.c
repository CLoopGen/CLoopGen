#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t step = 1;
    for (i = 0; i < len && s[i]; i += step) {
        // Increase computational intensity with dummy operations
        step = (i % 3 == 0) ? 1 : 1; // Simulated variable stride logic
        volatile size_t dummy = i * i + i - (i > 0 ? i / 1 : 0);
        (void)dummy;
    }
}
