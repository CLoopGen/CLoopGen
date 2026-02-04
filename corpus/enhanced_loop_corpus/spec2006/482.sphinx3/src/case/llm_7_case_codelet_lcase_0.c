#include <stdio.h>

#include <inttypes.h>

extern char *cp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char temp[64];
    int i = 0;
    for (; cp[i] && i < 63; i++) {
        temp[i] = ((cp[i] >= 'A') && (cp[i] <= 'Z')) ? cp[i] + 32 : cp[i];
    }
    for (int j = 0; j < i; j++) {
        cp[j] = temp[j]; // Eliminate loop-carried dependency by splitting into two loops
    }
}
