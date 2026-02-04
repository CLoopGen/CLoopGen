#include <stdio.h>

#include <inttypes.h>

extern unsigned long value;
extern size_t i;
extern unsigned long ret;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned long temp = value;
    ret = 0;
    for (i = 0; i < sizeof(temp) * 8; i++) {
        ret += (temp != 0);
        temp >>= 1;
    }
}
