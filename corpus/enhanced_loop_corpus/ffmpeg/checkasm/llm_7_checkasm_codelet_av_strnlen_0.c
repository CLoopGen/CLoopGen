#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j = 0;
    for (i = 0; j < len && s[j]; i++, j++) {
        // Replace direct use of 'i' in condition with 'j', creating a parallel induction variable
        // Introduces WAR-like potential between i and j, but no actual hazard due to comma operator sequencing
    }
    i = j;  // Final assignment to maintain semantic equivalence (i ends as the index of first null or len)
}
