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
for (t++; t < PL_bufend; t++) {
    if (*t == '\\' && t + 1 < PL_bufend)
        t++;
    else if (*t == close && --brackets <= 0)
        break;
    else if (*t == win32_open)
        brackets++;
}

}
