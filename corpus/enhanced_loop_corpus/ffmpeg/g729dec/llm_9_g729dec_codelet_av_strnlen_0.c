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
        for (j = 0; j < (i % 3) + 1; j++) {
            // Dummy operation to increase computational intensity
            volatile uint8_t dummy = (uint8_t)(s[i] ^ j);
        }
    }
}
