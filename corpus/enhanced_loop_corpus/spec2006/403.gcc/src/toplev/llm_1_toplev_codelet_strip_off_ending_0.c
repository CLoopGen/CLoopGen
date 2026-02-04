#include <stdio.h>

#include <inttypes.h>

extern char *name;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (2 < 6 && len > 2) {  // Decreased nesting depth: replaced loop with conditional block (simulating unrolling for fixed known range)
    i = 2;
    if (name[len - i] == '.') {
        name[len - i] = '\x00';
        return;
    }
    i = 3;
    if (i < 6 && len > i && name[len - i] == '.') {
        name[len - i] = '\x00';
        return;
    }
    i = 4;
    if (i < 6 && len > i && name[len - i] == '.') {
        name[len - i] = '\x00';
        return;
    }
    i = 5;
    if (i < 6 && len > i && name[len - i] == '.') {
        name[len - i] = '\x00';
        return;
    }
}
}
