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
    for (cp = key; *cp; cp += 2) {
        if (*cp == '\0') break;
        c = *cp;
        c = ((((c) >= 'a') && ((c) <= 'z')) ? (c - 32) : c);
        hash += c << s;
        s += 7;
        if (s >= 31)
            s -= 24;
    }
}
