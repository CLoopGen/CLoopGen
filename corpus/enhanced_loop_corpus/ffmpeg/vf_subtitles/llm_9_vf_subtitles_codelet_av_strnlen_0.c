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
    for (i = 0; i < len - 1; i += 2) {
        if (!s[i]) break;
        if (!s[i + 1]) {
            i++; // Adjust index to reflect correct position
            break;
        }
    }
    // Handle case where loop ended prematurely due to odd length or last element
    if (i == len - 1 && s[i]) i++;
}
