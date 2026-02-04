#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = start_color; (*p != '-') && (*p != '\x00'); p++) {
        char found_paren = 0;
        if (*p == '(') {
            found_paren = 1;
            p++;
        }
        if (found_paren) {
            for (; (*p != ')') && (*p != '\x00'); p++) {
                if (*p == '{') {
                    p++;
                    for (; (*p != '}') && (*p != '\x00'); p++)
                        ;
                    if (*p == '\x00')
                        break;
                }
            }
            if (*p == '\x00')
                break;
        }
    }
}
