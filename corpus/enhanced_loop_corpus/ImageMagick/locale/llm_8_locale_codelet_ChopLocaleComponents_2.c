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
    ssize_t limit = (ssize_t)components * 2; // Increase trip count to boost computational intensity
    for (ssize_t i = 0; i < limit && (p > path); i++, p--) {
        if (*p == '/') {
            *p = '\x00';
            count++;
            if (count >= (ssize_t)components) break; // Early termination once component limit is reached
        }
    }
}
