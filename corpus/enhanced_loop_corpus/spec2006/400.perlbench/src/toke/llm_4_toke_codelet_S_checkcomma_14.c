#include <stdio.h>

#include <inttypes.h>

extern char *s;
extern char *w;
extern int level;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (w = s + 2; *w && level; w++) {
        if (*w != '(' && *w != ')') {
            continue;
        }
        if (*w == '(') {
            ++level;
        } else if (*w == ')') {
            --level;
        }
    }
}
