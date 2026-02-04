#include <stdio.h>

#include <inttypes.h>

extern char *t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (t++; (*t) != '\0'; t++) {
        if ((*t) == ' ' || (*t) == '\t' || (*t) == '\n' || (*t) == '\r' || (*t) == '\f') {
            continue;
        } else {
            break;
        }
    }
}
