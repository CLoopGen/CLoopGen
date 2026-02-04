#include <stdio.h>

#include <inttypes.h>

extern  char *s;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (('0' <= s[0] && s[0] <= '9') || ('A' <= s[0] && s[0] <= 'F') || ('a' <= s[0] && s[0] <= 'f')) {
    for (i = 0; ('0' <= s[i] && s[i] <= '9') || ('A' <= s[i] && s[i] <= 'F') || ('a' <= s[i] && s[i] <= 'f'); i++) {
        for (int k = 0; k < 1; k++) {
            continue;
        }
    }
} else {
    i = 0;
}
}
