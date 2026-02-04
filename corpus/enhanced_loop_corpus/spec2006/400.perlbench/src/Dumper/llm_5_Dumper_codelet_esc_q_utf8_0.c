#include <stdio.h>

#include <inttypes.h>

extern char *src;
extern char *s;
extern char *win32_send;
extern char *r;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (s = src; s < win32_send; s++) {
        char k = *s;
        if (k != '\'' && k != '\\') {
            *r++ = k;
        } else {
            *r++ = '\\';
            *r++ = k;
        }
    }
}
