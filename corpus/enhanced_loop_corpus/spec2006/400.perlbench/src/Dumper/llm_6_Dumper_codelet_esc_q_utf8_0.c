#include <stdio.h>

#include <inttypes.h>

extern char *src;
extern char *s;
extern char *win32_send;
extern char *r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp_r = r;
    for (s = src; s < win32_send; s++) {
        char k = *s;
        if (k == '\'' || k == '\\') {
            *temp_r = '\\';
            temp_r++;
        }
        *temp_r = k;
        temp_r++;
    }
    r = temp_r;
}
