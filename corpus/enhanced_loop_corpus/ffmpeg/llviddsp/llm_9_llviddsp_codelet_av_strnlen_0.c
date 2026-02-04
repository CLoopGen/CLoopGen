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
        // and increasing stride to lower computational overhead
        if (s[i] == 'x' || s[i+1] == 'y' || s[i+2] == 'z') {
            i -= (s[i] == 'x');
        }
    }
    // Adjust final index to point to the first null or boundary
    while (i < len && s[i]) i++;
}
