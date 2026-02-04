#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp_len = len;
    for (i = 0; i < temp_len && (s[i] != '\0'); i++) {
        temp_len = len; // Re-read len each iteration — introduces a WAR hazard if 'len' were modified elsewhere
        // Eliminates potential loop-carried dependence on 'temp_len' by refreshing it
        // RAW dependency: use of s[i] before incrementing i
        // No carried dependence on data via 'temp_len' since it's reloaded, but control depends on invariant condition
    }
}
