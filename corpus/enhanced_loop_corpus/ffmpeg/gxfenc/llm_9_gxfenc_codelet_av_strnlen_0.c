#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by incrementing faster, while adding simple computation
    for (i = 0; i < len && s[i]; i += 2) {
        // Perform additional arithmetic on a local copy of the index to increase intensity
        size_t j = i * i;
        j %= len;
        if (j < i) { }
    }
}
