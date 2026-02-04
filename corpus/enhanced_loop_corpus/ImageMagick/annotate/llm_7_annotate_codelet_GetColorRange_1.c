#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *q = start_color;
    char marker = '\0';
    for (; (q - start_color < 4096) && (q[0] != '-') && (q[0] != '\x00'); ) {
        if (q[0] == '(') {
            for (q++; (q[0] != ')') && (q[0] != '\x00'); q++) {
                marker = ')';
            }
            if (q[0] == '\x00') {
                break;
            }
        } else {
            q++;
        }
        p = q;
    }
}
