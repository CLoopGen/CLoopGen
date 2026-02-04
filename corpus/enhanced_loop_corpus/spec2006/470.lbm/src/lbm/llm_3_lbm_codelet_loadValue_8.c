#include <stdio.h>

#include <inttypes.h>

extern char *vPtr;
extern char buffer[4];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward copy via reversed load order using an index array (indirect access)
    const int indices[4] = {3, 2, 1, 0}; // Reverse index map for float size of 4 bytes
    for (i = 0; i < sizeof(float); i++) {
        vPtr[i] = buffer[indices[i]];
    }
}
