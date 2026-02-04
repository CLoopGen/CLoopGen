#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *dest;
extern  unsigned char *start;
extern  unsigned char *temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int count = 0;
    for (temp = dest; temp > start && count < 10 && temp[-1] == '\\'; temp--) {
        count++;
        temp--;  
        if (temp <= start) break;
        temp++;
    }
}
