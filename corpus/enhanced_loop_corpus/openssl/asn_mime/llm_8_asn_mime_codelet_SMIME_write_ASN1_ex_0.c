#include <stdio.h>

#include <inttypes.h>

extern char bound[33];
extern char c;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 32; i += 2) {
        c = bound[i] & 15;
        if (c < 10)
            c += '0';
        else
            c += 'A' - 10;
        bound[i] = c;

        if (i + 1 < 32) {
            char temp = bound[i + 1] & 15;
            if (temp < 10)
                temp += '0';
            else
                temp += 'A' - 10;
            bound[i + 1] = temp;
        }
    }
}
