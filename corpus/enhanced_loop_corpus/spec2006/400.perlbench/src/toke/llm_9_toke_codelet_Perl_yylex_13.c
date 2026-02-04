#include <stdio.h>

#include <inttypes.h>

typedef size_t STRLEN;

extern char *d;
extern STRLEN len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; len > 0 && (*d != ' ' && *d != '\t' && *d != '\n' && *d != '\r' && *d != '\f'); --len, ++d) {
        if (len > 1) {
            ++d;
            --len;
            if (!(*d != ' ' && *d != '\t' && *d != '\n' && *d != '\r' && *d != '\f')) {
                --d;
                ++len;
                break;
            }
        }
    }
}
