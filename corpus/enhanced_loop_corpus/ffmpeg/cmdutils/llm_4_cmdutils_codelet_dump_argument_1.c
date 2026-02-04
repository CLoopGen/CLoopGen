#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *a;
extern  unsigned char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = a; *p; p++) {
        unsigned char ch = *p;
        if ((ch >= '+' && ch <= ':') || (ch >= '@' && ch <= 'Z') || ch == '_' || (ch >= 'a' && ch <= 'z')) {
            continue;
        } else {
            break;
        }
    }
}
