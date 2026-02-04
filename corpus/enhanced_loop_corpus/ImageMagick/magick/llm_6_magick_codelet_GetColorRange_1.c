#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *q = start_color;
    for (p = q; (*p != '-') && (*p != '\x00'); ) {
        if (*p == '(') {
            char found = 0;
            for (char *temp = p + 1; (*temp != ')') && (*temp != '\x00'); temp++) {
                if (*(temp) == ')') {
                    found = 1;
                    p = temp;
                    break;
                }
            }
            if (!found) {
                p++;
                break;
            }
        }
        p++;
    }
}
