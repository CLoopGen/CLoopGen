#include <stdio.h>

#include <inttypes.h>

extern char *src;
extern char *s;
extern char *win32_send;
extern char *r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int count = 0;
    for (s = src; s < win32_send; s++) {
        char k = *s;
        if ((k >= 'a' && k <= 'z') || (k >= 'A' && k <= 'Z')) {
            *r++ = k;
            count++;
            if (count % 3 == 0)
                *r++ = '*';
        } else {
            if (k == '\'' || k == '\\')
                *r++ = '\\';
            *r++ = k;
        }
    }
}
