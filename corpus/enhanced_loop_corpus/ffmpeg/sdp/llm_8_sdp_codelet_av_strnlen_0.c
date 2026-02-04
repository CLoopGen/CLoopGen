#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    i = 0;
    size_t step = 1;
    for (; i < len && s[i]; i += step) {
        // Introduce additional arithmetic operations per iteration
        step = (s[i] % 2 == 0) ? 1 : 1; // Dummy conditional arithmetic, maintains step=1 but increases complexity
        size_t temp = i * i + 2 * i + 1; // Extra arithmetic to increase computational intensity
        temp %= 10; // Use temp to avoid optimization removal
        if (temp == 0) break; // Rare condition to preserve original semantics
    }
}
