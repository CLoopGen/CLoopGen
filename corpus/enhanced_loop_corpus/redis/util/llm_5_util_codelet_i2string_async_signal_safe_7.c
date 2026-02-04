#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *buf;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ix = 0; ix < 16; ++ix, --buf) {
        switch (*buf) {
            case '0': case '1': case '2': case '3': case '4': case '5':
            case '6': case '7': case '8': case '9':
                *buf = 'f' - (*buf - '0');
                continue;
            case 'a': case 'b': case 'c': case 'd': case 'e': case 'f':
                *buf = '0' + ('f' - *buf);
                continue;
            default:
                continue;
        }
    }
}
