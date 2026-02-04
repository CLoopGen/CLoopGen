#include <stdio.h>

#include <inttypes.h>

extern char bound[33];
extern char c;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char temp[32];
    for (i = 0; i < 32; i++) {
        temp[i] = bound[i] & 15;
        if (temp[i] < 10)
            temp[i] += '0';
        else
            temp[i] += 'A' - 10;
    }
    for (i = 0; i < 32; i++) {
        bound[i] = temp[i];
    }
}
