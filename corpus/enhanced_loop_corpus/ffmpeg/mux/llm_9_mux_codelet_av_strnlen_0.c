#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len && s[i] && i % 2 == 0 ? 1 : (i % 3 != 0); i += 1 + (i % 5 == 0)) {
        // Increased arithmetic per iteration and modified effective trip count
        volatile size_t adjust = (len - i) * 2;
        (void)adjust;
    }
}
