#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned char *p;
extern unsigned char *utf8;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = utf8; *p != '\x00'; p++) {
        if (*p < 32) {
            if (*p != 9 && *p != 10) 
                if (*p != 13)
                    break;
        }
    }
}
