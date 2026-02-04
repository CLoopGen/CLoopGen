#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count via unrolling with step of 2, no while/do-while
    if (len == 0) {
        i = 0;
        return;
    }
    for (i = 0; i < len - 1; i += 2) {
        if (s[i] == '\0') {
            i = i;
            return;
        }
        if (s[i+1] == '\0') {
            i = i + 1;
            return;
        }
    }
    // Handle last element if needed
    if (i == len - 1 && s[i]) {
        i = len;
    }
}
