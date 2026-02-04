#include <stdio.h>

#include <inttypes.h>

extern int dialect_number;
extern  char *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < dialect_number; i++) {
        if (!(*p) || *p == '}') {
            break;
        }
        if (*p != '|') {
            p++;
            continue;
        }
        p++;
    }
}
