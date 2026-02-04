#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *dest;
extern  unsigned char *start;
extern  unsigned char *temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (temp = dest; temp > start; temp--) {
        if (temp[-1] != '\\') {
            break;
        }
    }
}
