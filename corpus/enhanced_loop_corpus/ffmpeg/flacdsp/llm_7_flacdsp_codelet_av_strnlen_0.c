#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char c;
    for (i = 0; i < len; i++) {
        c = s[i];  // Load into local variable to create temporary storage
        if (!c) break;  // Check the loaded value instead of directly branching on s[i]
        // Introduces a WAR hazard possibility if vectorized, but preserves correctness.
        // Loop-carried dependency on 'i' remains, but data dependency on 's[i]' is now split: load then test.
        // Eliminates combined bounds and null check fusion by separating access and exit logic.
    }
}
