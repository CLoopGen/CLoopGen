#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by stepping through every second element,
    // and add a conditional check that slightly increases per-iteration cost
    for (i = 0; i < len && s[i] && s[i+1]; i += 2) {
        if ((i % 3) == 0) {
            volatile size_t y = i * i;
            (void)y;
        }
    }
    // Ensure i is at most len (simulate original behavior's final state)
    if (i > len) i = len;
}
