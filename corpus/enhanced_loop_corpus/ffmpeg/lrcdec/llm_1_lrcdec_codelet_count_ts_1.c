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
    if (p[offset] == ' ' || p[offset] == '\t') {
        offset++;
    } else {
        for (;;){
            if (p[offset] == '[') {
                offset++;
                in_brackets++;
                break;
            } else if (p[offset] == ']' && in_brackets) {
                offset++;
                in_brackets--;
                break;
            } else if (in_brackets && (p[offset] == ':' || p[offset] == '.' || p[offset] == '-' || (p[offset] >= '0' && p[offset] <= '9'))) {
                offset++;
                break;
            } else {
                goto exit_all;
            }
        }
    }
}
exit_all:;
}
