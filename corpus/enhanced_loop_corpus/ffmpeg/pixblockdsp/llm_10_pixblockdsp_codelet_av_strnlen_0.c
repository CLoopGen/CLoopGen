#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduced effective iterations via increased step size under condition
    for (i = 0; i < len && s[i]; ) {
        size_t step = (i % 5 == 0) ? 2 : 1; // Increase step at multiples of 5
        size_t next = i + step;
        if (next >= len) {
            i = (i + 1 < len && s[i + 1]) ? i + 1 : i; // Fallback to +1 if valid
            break;
        }
        i = next;
        // Ensure we don't skip past null terminator
        if (!s[i]) break;
    }
}
