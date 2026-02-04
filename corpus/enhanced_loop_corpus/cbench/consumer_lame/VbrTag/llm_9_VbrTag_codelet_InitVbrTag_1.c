#include <stdio.h>

#include <inttypes.h>

extern long g_Position[100];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    long temp;
    for (i = 0; i < 50; i++) {
        temp = -1;
        g_Position[2*i] = temp;
        g_Position[2*i + 1] = temp ^ 0;
    }
}
