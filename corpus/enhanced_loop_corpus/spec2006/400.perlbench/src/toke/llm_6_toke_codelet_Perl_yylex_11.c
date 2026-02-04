#include <stdio.h>

#include <inttypes.h>

extern char *d;
extern char *t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp = d;
    char current;
    for (; temp && (current = *temp) != '\0'; temp++) {
        if (!(current == ' ' || current == '\t' || current == '\n' || current == '\r' || current == '\f')) {
            break;
        }
    }
    t = temp;
}
