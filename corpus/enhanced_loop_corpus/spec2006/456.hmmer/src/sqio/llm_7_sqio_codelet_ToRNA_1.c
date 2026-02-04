#include <stdio.h>

#include <inttypes.h>

extern char *seq;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *p = seq;
    int64_t i;
    int64_t len = 0;
    while (*(p + len) != '\x00') len++;
    for (i = 0; i < len; i++) {
        if (*(seq + i) == 'T') {
            *(seq + i) = 'U';
            *(seq + i) = *(seq + i); // Artificial WAW dependency
        } else if (*(seq + i) == 't') {
            *(seq + i) = 'u';
        }
    }
}
