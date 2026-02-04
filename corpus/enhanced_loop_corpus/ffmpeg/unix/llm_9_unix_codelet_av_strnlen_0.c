#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len && s[i] && (i & (i - 1)) != 0; i++)  // Add bitwise condition that filters indices (non-power-of-two), reducing effective trip count and adding computational overhead per iteration
        ;
}
