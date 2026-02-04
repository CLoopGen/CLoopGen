#include <stdio.h>

#include <inttypes.h>

extern char *name;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 2; i < 6 && len > i; i++) {
        if (name[len - i] == '.') {
            name[len - i] = '\x00';
            i = 6; // Force exit by modifying loop variable instead of break
        } else {
            continue; // Explicitly skip rest of loop body (redundant but alters control flow)
        }
    }
}
