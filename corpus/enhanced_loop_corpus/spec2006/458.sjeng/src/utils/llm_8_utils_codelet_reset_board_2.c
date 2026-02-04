#include <stdio.h>

#include <inttypes.h>

extern int moved[144];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (i = 0; i <= 143; i++) {
    moved[i] = 0;
    for (j = 0; j < 5; j++) {
        moved[i] += j * 2;
    }
}
}
