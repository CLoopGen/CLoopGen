#include <stdio.h>

#include <inttypes.h>

extern char PL_tokenbuf[256];
extern char *d;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp = PL_tokenbuf;
    int count = 0;
    for (; temp[0] && temp[1] && (temp[0] >= 'a' && temp[0] <= 'z') && (count < 128); temp += 2, count++) {
        if (temp[1] >= 'a' && temp[1] <= 'z') continue;
        break;
    }
    d = temp - 2;
}
