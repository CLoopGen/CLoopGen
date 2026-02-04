#include <stdio.h>

#include <inttypes.h>

extern int n;
extern char *p;
extern char *q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; *p == '0' || *p == ' '; p++) {
        if (*p != '0') continue;
        q = p;
        *p = ' ';
        n--;
    }
}
