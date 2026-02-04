#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len; i++) {
        if (!s[i])
            break;
        // Move the null-terminator check inside the loop body, eliminating the data dependency on 's[i]' in the condition
        // This removes the loop-carried dependence through the control flow from the original condition combining 'i < len' and 's[i]'
        // Now, only a pure RAW dependency exists: 's[i]' read after 'i' update
        // Semantics preserved: exits when null char is encountered or i reaches len
    }
}
