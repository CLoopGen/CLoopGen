#include <stdio.h>

#include <inttypes.h>

extern char *s;
extern char *win32_send;
extern char *base;
extern int maxops;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (base = s; s <= win32_send; s++) {
        if (*s != '\n' && *s != '@' && *s != '^')
            continue;
        maxops += 10;
    }
}
