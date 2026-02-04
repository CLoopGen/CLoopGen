#include <stdio.h>

#include <inttypes.h>

extern long g_Position[100];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    long temp[100];
    for (i = 0; i < 100; i++) {
        temp[i] = -1;
    }
    for (i = 0; i < 100; i++) {
        g_Position[i] = temp[i];
    }
}
