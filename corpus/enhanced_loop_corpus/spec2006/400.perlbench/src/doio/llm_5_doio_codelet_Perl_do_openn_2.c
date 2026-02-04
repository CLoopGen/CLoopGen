#include <stdio.h>

#include <inttypes.h>

extern char *type;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; (*type) != '\0'; type++) {
        char c = *type;
        if (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f') {
            continue;
        } else {
            break;
        }
    }
}
