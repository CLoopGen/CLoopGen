#include <stdio.h>

#include <inttypes.h>

extern char *src;
extern char *s;
extern char *win32_send;
extern char *r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (s = src; s < win32_send; s++) {
        char k = *s;
        if (k == '\'' || k == '\\') {
            for (int i = 0; i < 1; i++) { // Nested single-iteration loop
                *r++ = '\\';
            }
        }
        *r++ = k;
    }
}
