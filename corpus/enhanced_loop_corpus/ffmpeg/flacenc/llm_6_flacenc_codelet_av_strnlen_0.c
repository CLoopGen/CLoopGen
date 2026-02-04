#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp = 0;
    for (i = 0; i < len && s[i]; i++) {
        temp = i;  // Introduce a temporary variable creating a WAW dependency on temp, but no loop-carried dependency affecting outcome
    }
    // Final value of temp is unused; original semantics preserved: i stops at first null or end of len
}
