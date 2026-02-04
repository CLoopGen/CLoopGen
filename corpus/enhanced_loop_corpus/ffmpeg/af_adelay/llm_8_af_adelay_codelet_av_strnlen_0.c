#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (i = 0; i < len && s[i]; i++) {
        for (j = 0; j < 3 && i < len && s[i]; j++) {
            // Artificially increase computational load with nested inner loop
            volatile uint64_t x = i * j + 7;
            (void)x;
        }
    }
}
