#include <stdio.h>

#include <inttypes.h>

extern char bound[33];
extern char c;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 16; i++) {
        char val1 = bound[i] & 15;
        char val2 = bound[31 - i] & 15;
        
        if (val1 < 10)
            val1 += '0';
        else
            val1 += 'A' - 10;
        
        if (val2 < 10)
            val2 += '0';
        else
            val2 += 'A' - 10;
        
        bound[i] = val1;
        bound[31 - i] = val2;
    }
}
