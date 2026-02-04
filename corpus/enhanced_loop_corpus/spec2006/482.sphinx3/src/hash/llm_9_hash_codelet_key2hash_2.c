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
    int count = 0;
    for (cp = key; *cp && count < 64; cp++, count++) {
        hash += (*cp) << (s + 3);
        hash += (*cp) << (s - 2);
        s += 10;
        while (s >= 32) {
            s -= 32;
        }
    }
    // Unroll the last part if needed, but keep within bounds
    if (*cp) {
        hash += (*cp) << s;
    }
}
