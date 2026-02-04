#include <stdio.h>

#include <inttypes.h>

extern char *vPtr;
extern char buffer[4];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < sizeof(float); i += 2) {
        vPtr[i] = buffer[sizeof(float) - i - 1];
        if (i + 1 < sizeof(float)) {
            vPtr[i + 1] = buffer[sizeof(float) - (i + 1) - 1];
        }
    }
}
