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
for (count = 0; (count < (ssize_t)components) && (p > path); p--)
    if (*p == '/') {
        *p = '\x00';
        count++;
    }

}
