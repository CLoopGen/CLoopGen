#include <stdio.h>

#include <inttypes.h>

extern char *s;
extern char *t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive access with temporary array-like indexing using offset
    int offset = 0;
    char current;
    for (t = s; ; offset++) {
        current = *(s + offset);
        if (current != ' ' && current != '\t' && current != '\r') {
            t = s + offset;
            break;
        }
    }
}
