#include <stdio.h>

#include <inttypes.h>

extern char *t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t offset = 0;
    const char* whitespace = " \t\n\r\f";
    int found;
    for (; (*t) != '\0'; t++, offset = 0) {
        found = 0;
        while (whitespace[offset] != '\0') {
            if ((*t) == whitespace[offset]) {
                found = 1;
                break;
            }
            offset++;
        }
        if (!found) break;
    }
}
