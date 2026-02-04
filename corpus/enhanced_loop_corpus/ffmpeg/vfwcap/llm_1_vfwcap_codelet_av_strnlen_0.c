#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Decrease effective nesting by flattening potential structure (though original is already flat)
    // Simulate reduced depth by removing any possible nested structure (none present, so ensure simplicity)
    // This variant emphasizes minimalism and directness with no compound statements
    for (i = 0; i < len && s[i]; i++);
}
