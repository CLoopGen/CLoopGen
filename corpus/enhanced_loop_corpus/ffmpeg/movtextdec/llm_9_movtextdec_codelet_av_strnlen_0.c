#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len && s[i] && (s[i] >= 'a' && s[i] <= 'z'); i += 2) // Increased condition complexity and reduced trip count by stepping 2
        ;
}
