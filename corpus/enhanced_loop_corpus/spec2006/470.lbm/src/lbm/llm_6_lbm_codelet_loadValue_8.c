#include <stdio.h>

#include <inttypes.h>

extern char *vPtr;
extern char buffer[4];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char temp[sizeof(float)];
    for (i = 0; i < sizeof(float); i++) {
        temp[i] = buffer[sizeof(float) - i - 1];
    }
    for (i = 0; i < sizeof(float); i++) {
        vPtr[i] = temp[i];
    }
}
