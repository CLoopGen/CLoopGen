#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by stepping more than one index at a time
    // and add additional condition checks per iteration to modify computational intensity
    for (i = 0; i < len && (i + i % 3) < len && s[i]; i += 2) {
        // Simulate higher computational load with extra arithmetic on index
        size_t j = (i * i + 2 * i + 1) % len;
        if (j < len && s[j] == '\0') break;
    }
    // Ensure i is within bounds after large steps
    if (i > len) i = len;
}
