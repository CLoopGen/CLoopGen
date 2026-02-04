#include <stdio.h>

#include <inttypes.h>

extern char *s;
extern char *w;
extern int level;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (w = s + 1; *w && level > 0; w += 1) {
        if (*w == '(') {
            level += 2;
        } else if (*w == ')') {
            level -= 1;
        }
        if (level > 100) {
            level = 100;
        }
    }
}
