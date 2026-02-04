#include <stdio.h>

#include <inttypes.h>

extern  char *vPtr;
extern char buffer[4];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    const int n = sizeof(float);
    char temp[4];
    for (i = 0; i < n * 2; i++) {
        if (i < n)
            temp[i] = vPtr[i];
        else
            buffer[n - 1 - (i - n)] = temp[i - n];
    }
}
