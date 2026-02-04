#include <stdio.h>

#include <inttypes.h>

extern  char *s;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; ; i++) {
        char c = s[i];
        if (!(('0' <= c && c <= '9') || ('A' <= c && c <= 'F') || ('a' <= c && c <= 'f'))) break;
    }
}
