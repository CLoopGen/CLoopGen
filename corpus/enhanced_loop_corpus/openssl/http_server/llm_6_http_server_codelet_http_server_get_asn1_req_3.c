#include <stdio.h>

#include <inttypes.h>

extern char *url;
extern char *end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *ptr = url;
    char c;
    end = url;
    for (; (c = *ptr) != '\x00'; ptr++) {
        if (c == ' ') {
            end = ptr;
            break;
        }
        end = ptr + 1;
    }
}
