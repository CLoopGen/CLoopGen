#include <stdio.h>

#include <inttypes.h>

extern char *url;
extern char *end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    end = url;
    for (char *p = url; *p != '\x00'; ) {
        char ch = *p++;
        if (ch == ' ') {
            end = p - 1;
            break;
        }
        end = p;
    }
}
