#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (i = 0; i < len && s[i]; i++) {
        for (j = 0; j < 3 && (i + j) < len && s[i + j]; j++) {
            // Simulate increased computational load with bounded inner iterations
            if (s[i + j] == '\0') break;
        }
        i += j > 0 ? j - 1 : 0; // Skip processed characters to avoid redundant work
    }
}
