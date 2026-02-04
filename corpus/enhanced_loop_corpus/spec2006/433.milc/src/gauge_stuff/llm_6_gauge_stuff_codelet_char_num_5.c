#include <stdio.h>

#include <inttypes.h>

extern int length;
extern int j;
extern int bdig[6];
extern int old;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_old = 0;
    for (int i = length - 2; i >= 0; i--) {
        temp_old = temp_old * 10 + bdig[i];
    }
    old = temp_old;
}
