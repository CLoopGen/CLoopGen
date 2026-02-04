#include <stdio.h>

#include <inttypes.h>

extern int len;
extern  unsigned char *data;
extern unsigned int x[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int temp[16];
    for (i = 0; i < len; i++) {
        temp[i] = data[i];
        x[i] = temp[i]; // Introduces temporary storage, creating intra-loop WAW-like separation and breaking direct RAW from prior x[i] uses if any
    }
}
