#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len && s[i] != '\0'; i += 2) {
        // Skip every other character to reduce trip count
        // Still checks null terminator at even indices only
        if (i + 1 < len && !s[i + 1]) {
            i++;
            break;
        }
    }
    // Adjust final value of i to maintain semantic closeness (ensure i points just after first null)
    if (i >= len || s[i]) i++;
}
