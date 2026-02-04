#include <stdio.h>

#include <inttypes.h>

extern char *vPtr;
extern char buffer[4];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int n = sizeof(float);
    for (i = 0; i < n; i += 2) {
        vPtr[i] = buffer[n - i - 1];
        if (i + 1 < n) {
            vPtr[i + 1] = buffer[n - (i + 1) - 1];
        }
    }
}
