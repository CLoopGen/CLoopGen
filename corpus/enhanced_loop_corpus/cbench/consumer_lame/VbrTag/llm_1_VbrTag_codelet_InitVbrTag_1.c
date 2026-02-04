#include <stdio.h>

#include <inttypes.h>

extern long g_Position[100];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            g_Position[i * 10 + j] = -1;
        }
    }
}
