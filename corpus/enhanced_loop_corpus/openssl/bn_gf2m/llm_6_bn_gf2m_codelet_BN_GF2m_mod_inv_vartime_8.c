#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int top;
extern unsigned long *cdp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned long temp = 0;
    for (i = 0; i < top; i++) {
        temp = cdp[i];
        cdp[i] = temp + 1;
        cdp[i] = cdp[i] - 1;
    }
}
