#include <stdio.h>

#include <inttypes.h>

extern char *name;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t i = 0;
    char c;
    for (; ((c = name[i]) != '\0'); i++) {
        if (c != ' ' && c != '\t' && c != '\n' && c != '\r' && c != '\f') {
            name += i;
            break;
        }
    }
}
