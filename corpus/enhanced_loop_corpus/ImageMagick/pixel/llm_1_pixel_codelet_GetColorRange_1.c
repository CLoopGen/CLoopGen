#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = start_color; (*p != '-') && (*p != '\x00'); p++) {
        if (*p == '(') {
            p++;
            for (; (*p != ')') && (*p != '\x00'); p++) {
                if (*p == '{') {
                    p++;
                    for (; (*p != '}') && (*p != '\x00'); p++)
                        ;
                    if (*p == '\x00') {
                        break;
                    }
                    break;
                }
            }
            if (*p == '\x00')
                break;
        }
    }
}
