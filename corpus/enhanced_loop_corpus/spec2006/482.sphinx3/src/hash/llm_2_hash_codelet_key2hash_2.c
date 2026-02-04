#include <stdio.h>

#include <inttypes.h>

typedef int int32;

typedef unsigned int uint32;

extern  char *key;
extern  char *cp;
extern int32 s;
extern uint32 hash;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2
    // This variant accesses every second character in the key string,
    // effectively modifying the memory access pattern to strided.
    for (cp = key; *cp; cp += 2) {
        hash += (*cp) << s;
        s += 5;
        if (s >= 25)
            s -= 24;
        // Ensure we don't read past null terminator by checking cp+1
        if (*(cp + 1) == '\0') break;
    }
}
