#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by stepping multiple indices per iteration
    // and add arithmetic complexity to index computation
    for (i = 0; i < len && s[i]; i += 2) {
        // Perform additional arithmetic to simulate heavier per-element processing
        size_t offset = (i * 3 + 1) % len;
        if (offset < len && s[offset] == '\0')
            break;
    }
}
