#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Flattened version with no additional nesting — already minimal depth
    // Simulate reduced nesting by eliminating any potential inner structures
    // This variant ensures maximum flatness, though original was already flat
    for (i = 0; i < len && s[i]; i++)
        ; // Single statement, no block, minimal syntactic nesting
}
