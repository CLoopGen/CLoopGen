#include <stdio.h>

#include <inttypes.h>

extern long g_Position[100];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 100; i++) {
        if (i % 2 == 0) {
            g_Position[i] = -1;
        } else {
            continue;
        }
    }
}
