#include <stdio.h>

#include <inttypes.h>

typedef size_t STRLEN;

extern STRLEN len;
extern char *s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    STRLEN step = 2;
    STRLEN limit = (len + step - 1) / step;
    for (STRLEN i = 0; i < limit; i++) {
        STRLEN idx1 = i * step;
        STRLEN idx2 = idx1 + 1;
        if (idx1 < len) {
            char c1 = s[idx1];
            if (c1 >= 'A' && c1 <= 'Z') {
                s[idx1] = c1 + ('a' - 'A');
            }
        }
        if (idx2 < len) {
            char c2 = s[idx2];
            if (c2 >= 'A' && c2 <= 'Z') {
                s[idx2] = c2 + ('a' - 'A');
            }
        }
    }
    len = 0;
}
