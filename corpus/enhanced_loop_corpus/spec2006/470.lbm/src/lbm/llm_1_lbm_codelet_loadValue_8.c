#include <stdio.h>

#include <inttypes.h>

extern char *vPtr;
extern char buffer[4];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < sizeof(float); i++) {
        for (int k = 0; k < 1; k++)
            vPtr[i] = buffer[sizeof(float) - i - 1];
    }
}
