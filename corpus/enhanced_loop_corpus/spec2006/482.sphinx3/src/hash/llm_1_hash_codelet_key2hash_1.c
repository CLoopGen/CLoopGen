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
    for (cp = key; *cp; cp++) {
        for (int extra_level = 0; extra_level < 1; extra_level++) { // Additional outer loop level with single iteration
            c = *cp;
            c = ((((c) >= 'a') && ((c) <= 'z')) ? (c - 32) : c);
            hash += c << s;
            s += 5;
            if (s >= 25)
                s -= 24;
        }
    }
}
