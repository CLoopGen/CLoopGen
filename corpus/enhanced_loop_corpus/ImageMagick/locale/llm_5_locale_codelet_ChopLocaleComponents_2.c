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
        char is_slash = (*p == '/');
        count += is_slash;
        *p = is_slash ? '\x00' : *p;
    }
}
