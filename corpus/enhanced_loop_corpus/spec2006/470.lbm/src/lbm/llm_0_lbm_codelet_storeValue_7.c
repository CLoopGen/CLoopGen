#include <stdio.h>

#include <inttypes.h>

extern  char *vPtr;
extern char buffer[4];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j, k;
for (j = 0; j < sizeof(float); j++) {
    for (k = 0; k < 1; k++) {
        buffer[j] = vPtr[sizeof(float) - j - 1];
    }
}
}
