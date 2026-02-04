#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (i = 0; i <= 2; ++i) {
    j = i + 1;
    i = j - 1;
}
// Introduces WAR (write-after-read) and WAW dependencies by writing to 'i' after using it.
// Eliminates potential loop-carried dependencies on variables other than 'i'.
// The loop maintains the same iteration count but modifies 'i' in a way that preserves semantics.
}
