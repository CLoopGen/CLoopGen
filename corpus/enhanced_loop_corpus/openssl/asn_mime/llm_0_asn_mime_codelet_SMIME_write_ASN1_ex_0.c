#include <stdio.h>

#include <inttypes.h>

extern char bound[33];
extern char c;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 1; j++) {
        for (i = 0; i < 32; i++) {
            c = bound[i] & 15;
            if (c < 10)
                c += '0';
            else
                c += 'A' - 10;
            bound[i] = c;
        }
    }
}
