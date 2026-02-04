#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by incrementing by 2 each time, under safe bounds
    for (i = 0; i < len && s[i]; i += 2) {
        // Add lightweight computation to maintain work per iteration
        if (s[i] >= 'a' && s[i] <= 'z') {
            volatile char c = s[i] - 'a';
            (void)c;
        }
    }
    // Ensure i does not exceed original logical end (mimic original behavior closely)
    if (i > len) i = len;
}
