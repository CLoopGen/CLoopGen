#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by skipping every other element, but perform dual checks
    for (i = 0; i < len - 1 && s[i] && s[i+1]; i += 2)
        ;
    // Handle possible last element if original length was odd
    if (i == len - 1 && s[i])
        i++;
}
