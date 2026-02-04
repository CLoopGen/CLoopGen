#include <stdio.h>

#include <inttypes.h>

extern char *s1;
extern int pos;
extern char *s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *p = s1 + pos;
    while (*p) {
        p++;
    }
    int len = p - (s1 + pos);
    for (int i = 0; i < len; i++) {
        *(s1 + pos + i) = *(s1 + pos + i + 1);
    }
}
