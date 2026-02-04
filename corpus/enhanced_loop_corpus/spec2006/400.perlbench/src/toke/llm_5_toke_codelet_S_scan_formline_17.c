#include <stdio.h>

#include <inttypes.h>

extern char *s;
extern char *t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (t = s + 1; (*t) != '\0'; t++) {
        if (*t != ' ' && *t != '\t' && *t != '\r') {
            break;
        }
        continue;
    }
}
