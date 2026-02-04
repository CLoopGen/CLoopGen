#include <stdio.h>

#include <inttypes.h>

extern char *s1;
extern char c;
extern int pos;
extern char oldc;
extern char *s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *ptr;
    int i = 0;
    for (ptr = s1 + pos; *(ptr + i); i++) {
        *(ptr + i) = c;
    }
    c = *(ptr + i - 1);
}
