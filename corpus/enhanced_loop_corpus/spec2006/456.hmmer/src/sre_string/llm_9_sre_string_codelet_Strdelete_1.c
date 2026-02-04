#include <stdio.h>

#include <inttypes.h>

extern char *s1;
extern int pos;
extern char *s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (s = s1 + pos; *s && *(s + 1); s += 2) {
        *s = *(s + 1);
        if (*(s + 1)) {
            *(s + 1) = *(s + 2);
        }
    }
    if (*s == *(s + 1) && *(s + 1) == '\0') {
        *s = '\0';
    }
}
