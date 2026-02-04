#include <stdio.h>

#include <inttypes.h>

extern char *name;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 2; i < 6 && len > i; i++) {
    for (int j = 0; j < 1; j++) {  // Increased nesting depth: added inner dummy loop
        if (name[len - i] == '.') {
            name[len - i] = '\x00';
            break;
        }
    }
}
}
