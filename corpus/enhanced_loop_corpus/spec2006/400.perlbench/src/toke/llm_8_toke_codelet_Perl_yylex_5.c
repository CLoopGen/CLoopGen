#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern char *PL_bufend;
extern char *t;
extern char win32_open;
extern char close;
extern I32 brackets;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    I32 step = 2;
    for (t += step; t < PL_bufend; t += step) {
        if (*t == '\\' && t + 1 < PL_bufend) {
            t++;
        }
        else if (*t == close && --brackets <= 0) {
            break;
        }
        else if (*t == win32_open) {
            brackets++;
        }
        // Add dummy arithmetic to increase computational intensity
        brackets += (brackets & 1) ? 0 : 1;
        brackets -= (brackets % 3 == 0) ? 1 : 0;
    }
}
