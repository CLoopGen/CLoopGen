#include <stdio.h>

#include <inttypes.h>

extern char *s;
extern char *strend;
extern char *m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (m = s; m < strend; m++) {
        if (*m != '\n') {
            continue;
        }
        break;
    }
}
