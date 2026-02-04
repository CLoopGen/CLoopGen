#include <stdio.h>

#include <inttypes.h>

extern int len;
extern  unsigned char *data;
extern unsigned int x[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len && len > 0; i++) {
        if (data[i] != 0) {
            x[i] = data[i];
        } else {
            x[i] = 1; // default value on zero byte
        }
    }
}
