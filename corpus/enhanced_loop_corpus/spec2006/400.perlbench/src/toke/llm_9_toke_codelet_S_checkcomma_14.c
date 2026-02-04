#include <stdio.h>

#include <inttypes.h>

extern char *s;
extern char *w;
extern int level;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 1 << level;
    if (stride < 1) stride = 1;
    for (w = s + 2; *w && level; w += stride) {
        if (*w == '(') {
            ++level;
        } else if (*w == ')') {
            --level;
        }
        if (w[1] == '(' && level > 0) {
            ++w;
            ++level;
        }
    }
}
