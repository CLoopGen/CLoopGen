#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len && s[i] && i < 1000; i++) {
        if ((i & 7) == 0) {  // Perform extra work every 8th iteration
            volatile uint32_t dummy = i * i + i - 1;
            (void)dummy;
        }
    }
}
