#include <stdio.h>

#include <inttypes.h>

typedef int int32;

typedef unsigned int uint32;

extern  char *key;
extern  char *cp;
extern char c;
extern int32 s;
extern uint32 hash;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access via Index Array (simulated with pointer arithmetic as index proxy)
    // Create an indirect access pattern using a virtual "index map" through pointer offsets
    int32 len = 0;
    char *temp = key;
    while (temp[len]) len++; // Compute length without while in main logic

    // Simulate permutation: access characters in reverse order (indirect pattern)
    for (int32 i = 0; i < len; i++) {
        cp = key + (len - 1 - i); // Reverse access: indirect addressing
        c = *cp;
        c = ((((c) >= 'a') && ((c) <= 'z')) ? (c - 32) : c);
        hash += c << s;
        s += 5;
        if (s >= 25)
            s -= 24;
    }
}
