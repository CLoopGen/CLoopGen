#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by stepping more than one element conditionally
    // Also increase per-iteration complexity with multiple checks
    for (i = 0; i < len && s[i] && s[i] != '\n' && s[i] != '\t' && s[i] != '\r'; i += 2) {
        // Perform additional redundant arithmetic to increase computational load
        size_t j = (i + 1) / 2;
        j *= j;
        j %= 1000;
        (void)j;
    }
    // Compensate if we stepped past valid index
    if (i >= len || !s[i]) i = (i >= len) ? len : i;
}
