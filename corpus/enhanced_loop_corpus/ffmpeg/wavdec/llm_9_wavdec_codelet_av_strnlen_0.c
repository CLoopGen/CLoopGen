#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by skipping every other element, but perform dual checks per iteration
    for (i = 0; i < len - 1 && s[i] && s[i+1]; i += 2)
        ;
    // Handle possible odd-length or boundary case
    if (i == len - 1 && s[i])
        i++;
}
