#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j = 0;
    for (i = 0; j < len && s[j]; i++, j++) {
        // Introduce a temporary variable 'j' to break direct loop-carried dependency on 'i'
        // Original loop used 'i' for both indexing and counting; now 'j' controls array access
        // This creates a WAW anti-dependency between 'i' and 'j', but removes RAW dependency of index from increment
    }
    i = j; // Final value of i matches original: position of null or end of buffer
}
