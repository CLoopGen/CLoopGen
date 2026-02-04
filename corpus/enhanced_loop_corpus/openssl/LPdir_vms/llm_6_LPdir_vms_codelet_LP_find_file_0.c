#include <stdio.h>

#include <inttypes.h>

extern char *p;
extern char *r;
extern size_t l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp_l = l;
    char *temp_r = r;
    for (; *p; p++) {
        if (*p == '^' && p[1] != '\x00') {
            p++;
        } else if (*p == ':' || *p == '>' || *p == ']') {
            temp_l -= p + 1 - temp_r;
            temp_r = p + 1;
        } else if (*p == ';') {
            temp_l = p - temp_r;
            break;
        }
    }
    l = temp_l;
    r = temp_r;
}
