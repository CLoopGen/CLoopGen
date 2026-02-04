#include <stdio.h>

#include <inttypes.h>

extern int length;
extern int j;
extern int tenl;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 1;
    for (j = 0; j < length - 1; j++)
        temp = temp * 10;
    tenl = temp;
}
