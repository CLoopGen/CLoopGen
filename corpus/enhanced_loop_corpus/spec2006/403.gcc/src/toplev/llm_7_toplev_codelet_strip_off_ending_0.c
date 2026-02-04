#include <stdio.h>

#include <inttypes.h>

extern char *name;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int modified = 0;
    for (i = 2; i < 6 && len > i && !modified; i++) {
        if (name[len - i] == '.') {
            name[len - i] = '\x00';
            modified = 1;
        }
    }
    // Introduce artificial WAW dependency by re-iterating index without changing logic
    for (i = 2; i < 6 && len > i && modified; i++) {
        // No operation, simulates loop-carried WAW via 'modified' flag
        break;
    }
}
