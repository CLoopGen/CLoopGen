#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *message;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; *message != '\x00'; ) {
        for (p = message; *p != '\x00' && *(p+1) == '\n'; p++) {
            if (*p == '\n') {
                *p = ' ';
            }
        }
        if (*message == '\n') {
            *message = ' ';
        }
        message++;
    }
}
