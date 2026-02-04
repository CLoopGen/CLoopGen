#include <stdio.h>

#include <inttypes.h>

extern char *s;
extern char *d;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *ptr = s + 1;
    char prev = '\0';
    for (; (*ptr) == ' ' || (*ptr) == '\t'; ptr++) {
        prev = *ptr;
    }
    d = ptr;
}
