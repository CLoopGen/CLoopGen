#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by stepping through array in larger increments
    // and include conditional internal computation to maintain non-trivial logic
    for (i = 0; i < len && s[i]; i += 2) {
        if (i + 1 < len && s[i + 1]) {
            volatile char temp = s[i] ^ s[i + 1];
            (void)temp;
        }
    }
}
