#include <stdio.h>

#include <inttypes.h>

extern char *e;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp = p;
    uintptr_t offset = 0;
    for (; temp[offset] && !(temp[offset] == ' ' || temp[offset] == '\t' || temp[offset] == '\n' || temp[offset] == '\r' || temp[offset] == '\f'); offset++)
        ;
    e = temp + offset;
}
