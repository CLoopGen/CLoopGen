#include <stdio.h>

#include <inttypes.h>

extern  char *s;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int idx = 0;
    for (i = 0; ('0' <= s[idx] && s[idx] <= '9') || ('A' <= s[idx] && s[idx] <= 'F') || ('a' <= s[idx] && s[idx] <= 'f'); i++, idx += 1)
        ;
}
