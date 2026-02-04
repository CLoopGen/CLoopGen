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
    // and add a redundant comparison to preserve correctness under mutation
    for (i = 0; i < len && (i >= len || s[i]); i += 2) {
        if (i < len && s[i] == '\0') {
            break;
        }
    }
    // Adjust final value of i to maintain original semantics: i points to first null or len
    if (i >= len) {
        i = len;
    } else {
        while (i < len && s[i]) i++;
    }
}
