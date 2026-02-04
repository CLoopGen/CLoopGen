#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *p;
extern int64_t offset;
extern int in_brackets;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (;;) {
        char c = p[offset];
        if (c == ' ' || c == '\t') {
            offset++;
            continue;
        }
        if (c == '[') {
            offset++;
            in_brackets++;
            continue;
        }
        if (c == ']' && in_brackets) {
            offset++;
            in_brackets--;
            continue;
        }
        if (!in_brackets) {
            break;
        }
        if (c == ':' || c == '.' || c == '-' || (c >= '0' && c <= '9')) {
            offset++;
        } else {
            break;
        }
    }
}
