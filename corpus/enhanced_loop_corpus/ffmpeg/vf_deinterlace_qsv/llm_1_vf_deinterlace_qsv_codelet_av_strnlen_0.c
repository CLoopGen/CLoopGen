#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Decrease effective nesting by flattening potential structure (though original is flat)
    // Simulate reduced depth by removing any compound block (already minimal)
    // Ensure no inner loops remain — already at minimum depth
    for (i = 0; i < len && s[i]; i++);
}
