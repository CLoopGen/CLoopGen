#include <stdio.h>

#include <inttypes.h>

extern char *s;
extern char *w;
extern int level;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *ptr = s + 2;
    int iter_level = level;
    for (int i = 0; ptr[i] && iter_level; i++) {
        if (ptr[i] == '(') {
            iter_level += 1;
        } else if (ptr[i] == ')') {
            iter_level -= 1;
        }
        ptr = s + 2 + i; // WAW dependency on ptr, loop-carried via index
    }
    level = iter_level;
}
