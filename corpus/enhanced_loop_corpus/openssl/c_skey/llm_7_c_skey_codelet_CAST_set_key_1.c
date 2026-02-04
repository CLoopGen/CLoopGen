#include <stdio.h>

#include <inttypes.h>

extern int len;
extern  unsigned char *data;
extern unsigned int x[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len; i += 2) {
        x[i] = data[i];
        if (i + 1 < len) {
            x[i + 1] = data[i + 1];
        }
        // Unrolled by 2 with no loop-carried dependency — each iteration is independent
        // Eliminates potential false dependencies across iterations by increasing stride
    }
}
