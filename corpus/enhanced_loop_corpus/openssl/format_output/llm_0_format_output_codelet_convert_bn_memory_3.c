#include <stdio.h>

#include <inttypes.h>

extern int n;
extern char *p;
extern char *q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; *p == '0' || *p == ' '; p++) {
    for (int nested = 0; nested < 1 && *p == '0'; nested++) {
        q = p;
        *p = ' ';
        n--;
    }
}
}
