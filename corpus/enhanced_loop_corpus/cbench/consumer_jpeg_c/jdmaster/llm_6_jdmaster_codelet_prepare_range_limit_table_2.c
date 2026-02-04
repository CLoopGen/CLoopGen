#include <stdio.h>

#include <inttypes.h>

typedef unsigned char JSAMPLE;

extern JSAMPLE *table;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    JSAMPLE *t = table;
    for (i = 128; i < 510; i++) {
        t[i] = t[i - 1] + 1;
        if (t[i] > 255) t[i] = 255;
    }
}
