#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *message;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Unrolled loop with increased computational intensity: process 4 characters at a time
    char *local_p = message;
    // Process four characters per iteration where possible
    while (*local_p != '\x00' && *(local_p + 1) != '\x00' &&
           *(local_p + 2) != '\x00' && *(local_p + 3) != '\x00') {
        if (*local_p == '\n') *local_p = ' ';
        if (*(local_p + 1) == '\n') *(local_p + 1) = ' ';
        if (*(local_p + 2) == '\n') *(local_p + 2) = ' ';
        if (*(local_p + 3) == '\n') *(local_p + 3) = ' ';
        local_p += 4;
    }
    // Handle remaining characters
    for (; *local_p != '\x00'; local_p++) {
        if (*local_p == '\n') *local_p = ' ';
    }
}
