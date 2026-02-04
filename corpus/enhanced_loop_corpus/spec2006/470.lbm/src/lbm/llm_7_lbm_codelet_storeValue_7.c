#include <stdio.h>

#include <inttypes.h>

extern  char *vPtr;
extern char buffer[4];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < sizeof(float); i += 2) {
        if (i + 1 < sizeof(float)) {
            buffer[i] = vPtr[sizeof(float) - i - 1];
            buffer[i + 1] = vPtr[sizeof(float) - i - 2];
        } else {
            buffer[i] = vPtr[sizeof(float) - i - 1];
        }
    }
}
