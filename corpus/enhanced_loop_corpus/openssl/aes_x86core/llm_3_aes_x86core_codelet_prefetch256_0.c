#include <stdio.h>

#include <inttypes.h>

extern volatile unsigned long *t;
extern unsigned long sum;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int indices[] = {0, 32/sizeof(t[0]), 64/sizeof(t[0]), 96/sizeof(t[0]), 
                     128/sizeof(t[0]), 160/sizeof(t[0]), 192/sizeof(t[0]), 224/sizeof(t[0])};
    sum = 0;
    for (i = 0; i < 8; i++) {
        sum ^= t[indices[i]];
    }
}
