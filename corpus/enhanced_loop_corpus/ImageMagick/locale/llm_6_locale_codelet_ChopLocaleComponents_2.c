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
    ssize_t temp_count = 0;
    char *temp_p = p;
    for (count = 0; (count < (ssize_t)components) && (temp_p > path); temp_p--) {
        if (*temp_p == '/') {
            *(temp_p) = '\x00';
            temp_count++;
        }
    }
    count = temp_count;
}
