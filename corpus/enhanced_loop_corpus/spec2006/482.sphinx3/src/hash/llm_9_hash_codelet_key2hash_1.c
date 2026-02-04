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
    for (cp = key; *cp && *(cp+1); cp++) {
        char chars[2] = {cp[0], cp[1]};
        for (int i = 0; i < 2; i++) {
            c = chars[i];
            c = ((((c) >= 'a') && ((c) <= 'z')) ? (c - 32) : c);
            hash += c << s;
            s += 5;
            if (s >= 25)
                s -= 24;
        }
    }
    // Handle odd-length string tail
    if (*cp) {
        c = *cp;
        c = ((((c) >= 'a') && ((c) <= 'z')) ? (c - 32) : c);
        hash += c << s;
        s += 5;
        if (s >= 25)
            s -= 24;
    }
}
