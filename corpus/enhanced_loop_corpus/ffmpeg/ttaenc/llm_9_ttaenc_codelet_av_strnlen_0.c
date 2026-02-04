#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by iterating over every second element, then verify continuity
    for (i = 0; i < len && i + 1 < len && s[i] && s[i + 1]; i += 2)
        ;
    // Finalize with single increment if needed and original condition still holds
    if (i < len && s[i]) i++;
}
