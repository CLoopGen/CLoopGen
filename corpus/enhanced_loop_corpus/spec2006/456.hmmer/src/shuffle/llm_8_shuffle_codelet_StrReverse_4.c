#include <stdio.h>

#include <inttypes.h>

extern char *s1;
extern char *s2;
extern int len;
extern int pos;
extern char c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = 0; i < len; i++) {
        if (i < len / 2) {
            c = s2[len - i - 1];
            s1[len - i - 1] = s2[i];
            s1[i] = c;
        }
    }
}
