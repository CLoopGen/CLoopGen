#include <stdio.h>

#include <inttypes.h>

extern unsigned char *buf;
extern int i;
extern unsigned char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 1; j++)
        for (i = 0; i < sizeof(double); i++)
            buf[i] = p[i];
}
