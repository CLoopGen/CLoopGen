#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *ext;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (int i = 0; i < 3; i++) {
    if (*ext == '\x00') {
        p[i] = ' ';
    } else {
        p[i] = *ext++;
    }
}

}
