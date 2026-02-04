#include <stdio.h>

#include <inttypes.h>

extern char *PL_bufend;
extern char *t;
extern char win32_open;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp;
    for (t++; t < PL_bufend; t++) {
        temp = t + 1;
        if (*t == '\\' && temp < PL_bufend && win32_open != '\\') {
            t++;
        }
        else if (*t == win32_open) {
            break;
        }
    }
}
