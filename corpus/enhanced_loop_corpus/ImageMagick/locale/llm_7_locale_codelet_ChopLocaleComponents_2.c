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
    char *local_p = p;
    ssize_t local_count = 0;
    for (; (local_count < (ssize_t)components) && (local_p > path); ) {
        char c = *local_p;
        if (c == '/') {
            *local_p = '\x00';
            local_count = local_count + 1;
        }
        local_p--;
    }
    count = local_count;
    p = local_p;
}
