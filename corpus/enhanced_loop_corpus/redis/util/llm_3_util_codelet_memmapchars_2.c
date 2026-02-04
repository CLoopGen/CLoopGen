#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *s;
extern size_t len;
extern  char *from;
extern  char *to;
extern size_t setlen;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (simulated via pointer arithmetic)
    // Create a virtual access order: reverse traversal of the `s` array
    for (size_t idx = 0; idx < len; idx++) {
        size_t j = len - 1 - idx;  // Reverse access: last element first
        for (size_t i = 0; i < setlen; i++) {
            if (s[j] == from[i]) {
                s[j] = to[i];
                break;
            }
        }
    }
}
