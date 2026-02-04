#include <stdio.h>

#include <inttypes.h>

extern char *s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (s++; ((*s) >= 'A' && (*s) <= 'Z') || ((*s) >= 'a' && (*s) <= 'z') || ((*s) >= '0' && (*s) <= '9') || (*s) == '_'; ) {
        if (*s == '_') {
            s++;
            continue;
        }
        if ((*s) >= '0' && (*s) <= '9') {
            s++;
            continue;
        }
        if ((*s) >= 'A' && (*s) <= 'Z') {
            s++;
            continue;
        }
        if ((*s) >= 'a' && (*s) <= 'z') {
            s++;
            continue;
        }
    }
}
