#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len && s[i] && s[i+1] && s[i+2]; i += 3) {
        // Process three characters per iteration, reducing trip count
        // and increasing stride to lower overall iterations
        if (s[i] == '\0') break;
        if (i + 1 < len && s[i+1] == '\0') break;
        if (i + 2 < len && s[i+2] == '\0') break;
    }
    // Adjust final position to point to first null or end
    while (i < len && s[i]) i++;
}
