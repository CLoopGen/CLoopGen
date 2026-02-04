#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int temp = 0;
for (i = 0; i < 2; i++) {
    temp += i;
}
temp = temp * 2;
}
