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
        // Introduce a new induction variable j that breaks direct use of i in addressing
        // This removes the loop-carried dependence on i being used for both counting and indexing
        // RAW dependency between s[j] and j is preserved, but i now runs parallel to j without direct data flow
    }
}
