#include <stdio.h>

#include <inttypes.h>

extern char *s;
extern char *win32_send;
extern char *base;
extern int maxops;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (base = s; s <= win32_send; s++) {
        for (int offset = 0; offset < 1; offset++) {
            if (*(s + offset) == '\n' || *(s + offset) == '@' || *(s + offset) == '^')
                maxops += 10;
        }
    }
}
