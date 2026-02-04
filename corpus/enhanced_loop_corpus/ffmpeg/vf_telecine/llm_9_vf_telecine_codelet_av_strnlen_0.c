#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by stepping more than one element at a time
    // and include conditional check within the body to maintain correctness
    for (i = 0; i < len; i += 2) {
        if (s[i] == '\0') break;
        if (i + 1 < len && s[i + 1] == '\0') {
            i++;
            break;
        }
    }
}
