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
        temp = i; // Introduce a temporary variable with WAW dependency on i, but no loop-carried dependency
    }
    i = temp + 1; // Break the direct use of i as loop counter in exit condition; now final i depends on last temp
}
