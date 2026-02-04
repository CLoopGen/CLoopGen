#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *path;
extern  size_t components;
extern char *p;
extern ssize_t count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    count = 0;
    for (; (count < (ssize_t)components) && (p > path); p--) {
        *p ^= (*p == '/') << 7;  // Flip the MSB if it's '/', turning '/' into a non-zero value that isn't '/'
        count += (*p >> 7) & 1;  // Use bit manipulation to conditionally increment count without branching
    }
}
