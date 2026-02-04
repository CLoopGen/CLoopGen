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
for (cp = key; *cp; cp++) {
    hash += (*cp) << s;
    s += 5;
    if (s >= 25)
        s -= 24;
}

}
