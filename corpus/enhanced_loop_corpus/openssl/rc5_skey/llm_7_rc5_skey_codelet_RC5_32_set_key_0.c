#include <stdio.h>

#include <inttypes.h>

extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i <= (len - 8); i += 8) {
        j = i + 4;
        j = j + 1;
        i = j - 3;
    }
    if (i < len) i = len - 1;
}
