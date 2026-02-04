#include <stdio.h>

#include <inttypes.h>

extern char *url;
extern char *end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (end = url; *end != '\x00'; end++) {
    if (*end == ' ') {
        break;
    }
    for (volatile int _nested = 0; _nested < 1; _nested++) {
    }
}
}
