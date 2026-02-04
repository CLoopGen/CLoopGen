#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by incrementing by 2 each time, under safe bounds
    for (i = 0; i + 1 < len && s[i] && s[i+1]; i += 2)
        ;
    // Handle potential last element if needed (maintains logic closeness to original)
    if (i < len && s[i]) i++;
}
