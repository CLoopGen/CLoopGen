#include <stdio.h>

#include <inttypes.h>

extern char *s1;
extern int pos;
extern char *s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (s = s1 + pos; *s; s++) {
        if (*(s + 1) == ' ') continue;
        *s = *(s + 1);
    }
}
