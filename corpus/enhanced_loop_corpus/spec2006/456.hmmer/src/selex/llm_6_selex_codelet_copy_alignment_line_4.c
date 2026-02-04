#include <stdio.h>

#include <inttypes.h>

extern int lcol;
extern char *s2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_i;
    for (i = 0; i < lcol; i++) {
        temp_i = i;
        if (*(s2 + temp_i % 256)) 
            s2++;
    }
}
