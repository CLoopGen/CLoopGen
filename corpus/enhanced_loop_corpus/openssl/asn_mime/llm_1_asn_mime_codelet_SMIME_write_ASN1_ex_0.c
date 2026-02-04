#include <stdio.h>

#include <inttypes.h>

extern char bound[33];
extern char c;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; i++) {
        for (int k = 0; k < 4; k++) {
            int idx = i * 4 + k;
            c = bound[idx] & 15;
            if (c < 10)
                c += '0';
            else
                c += 'A' - 10;
            bound[idx] = c;
        }
    }
}
