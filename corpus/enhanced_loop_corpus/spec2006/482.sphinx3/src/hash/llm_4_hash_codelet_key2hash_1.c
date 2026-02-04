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
        c = *cp;
        if (!((c >= 'a') && (c <= 'z'))) {
            hash += c << s;
            s += 5;
            if (s >= 25)
                s -= 24;
            continue;
        }
        c = c - 32;
        hash += c << s;
        s += 5;
        if (s >= 25)
            s -= 24;
    }
}
