#include <stdio.h>

#include <inttypes.h>

extern  unsigned short *p;
extern unsigned short *q;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned short temp;
    for (i = 0; i < 6 - 1; i++) {
        temp = *p--;     // Load into temporary to break direct dependency
        *q++ = temp;     // Store from temporary, reducing potential WAW/WAR hazards
    }
}
