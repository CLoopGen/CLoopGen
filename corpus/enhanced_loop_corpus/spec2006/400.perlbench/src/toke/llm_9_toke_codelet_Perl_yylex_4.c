#include <stdio.h>

#include <inttypes.h>

extern char *PL_bufend;
extern char *t;
extern char win32_open;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int skip_next = 0;
    char target = win32_open;
    for (t++; t < PL_bufend && !skip_next; t++) {
        if (*t == '\\' && (t + 1) < PL_bufend && target != '\\') {
            t++;
        } else if (*t == target) {
            skip_next = 1;
            break;
        }
    }
    if (skip_next)
        t--;
}
