#include <stdio.h>

#include <inttypes.h>

extern char *s;
extern char *t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp = s;
    char c;
    for (; temp != NULL; temp++) {
        c = *temp;
        if (!(c == ' ' || c == '\t' || c == '\r')) {
            t = temp;
            break;
        }
    }
}
