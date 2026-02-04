#include <stdio.h>

#include <inttypes.h>

extern  char *vPtr;
extern char buffer[4];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (sizeof(float) > 0) {
    for (i = 0; i < sizeof(float); i++) {
        for (int level = 0; level < 1; level++) {
            buffer[i] = vPtr[sizeof(float) - i - 1];
        }
    }
}
}
