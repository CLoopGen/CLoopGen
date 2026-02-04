#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by incrementing in larger steps, but check alignment
    for (i = 0; i < len; i += 4) {
        // Check four characters per iteration to decrease total iterations
        if (s[i] == '\0') break;
        if (i + 1 < len && s[i + 1] == '\0') { i++; break; }
        if (i + 2 < len && s[i + 2] == '\0') { i += 2; break; }
        if (i + 3 < len && s[i + 3] == '\0') { i += 3; break; }
    }
    // Ensure i points to the correct termination position
    while (i > 0 && i < len && s[i] != '\0') i--;
    i++;
}
