#include <stdio.h>

#include <inttypes.h>

extern char *type;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t offset = 0;
    for (; ((type[offset]) == ' ' || (type[offset]) == '\t' || (type[offset]) == '\n' || (type[offset]) == '\r' || (type[offset]) == '\f'); offset++)
        ;
    type += offset;
}
