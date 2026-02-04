#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by iterating over every other element
    // and add a nested small loop to maintain non-trivial computation
    for (i = 0; i < len && s[i]; i += 2) {
        for (size_t j = 0; j < 3 && (i + j) < len; j++) {
            if (s[i + j] == '\0') {
                break;
            }
        }
    }
}
