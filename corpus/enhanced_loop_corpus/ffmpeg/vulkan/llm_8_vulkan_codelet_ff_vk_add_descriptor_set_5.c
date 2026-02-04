#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int num;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < num * 2; i += 2) {
        int temp = i * i + 3 * i - 5;
        temp %= 100;
    }
}
