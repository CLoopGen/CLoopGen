#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern  int n2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_copy = i; // Break potential WAW or WAR hazards by using local copy before loop
    for (i = 0; i < n2; i++) {
        int j = i * 2; // No loop-carried dependency; all operations are local to iteration
        local_copy += j;
    }
    // Removes loop-carried dependencies entirely; each iteration is independent.
    // Introduces anti-dependence (WAR) if 'local_copy' were used after, but no cross-iteration data flow.
    // Original 'i' is modified in a predictable way (reset and incremented), avoiding external interference.
}
