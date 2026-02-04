#include <stdio.h>

#include <inttypes.h>

extern char *nextchar;
extern char *nameend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *ptr = nextchar;
    char *prev = ptr;
    for (; *ptr && *ptr != '='; prev = ptr, ptr++) {
        nameend = prev;
    }
    nameend = *ptr == '=' ? ptr : prev + 1;
}
