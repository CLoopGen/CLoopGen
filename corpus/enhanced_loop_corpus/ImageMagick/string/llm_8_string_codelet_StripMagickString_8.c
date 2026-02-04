#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *message;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ptrdiff_t len = 0;
    char *start = message;
    while (*(start + len) != '\x00') len++;  // First, compute length manually without direct pointer increment in for-loop
    for (ptrdiff_t i = 0; i < len; i++) {
        if (*(message + i) == '\n') {
            *(message + i) = ' ';
        }
    }
}
