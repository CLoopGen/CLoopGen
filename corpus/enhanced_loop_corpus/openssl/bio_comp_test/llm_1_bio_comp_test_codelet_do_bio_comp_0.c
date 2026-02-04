#include <stdio.h>

#include <inttypes.h>

extern unsigned char *original;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i, j, k;
    for (i = 0; i < 8; i++)
        for (j = 0; j < 8; j++)
            for (k = 0; k < 512; k++) {
                int index = (i * 8 + j) * 512 + k;
                if (index < 32 * 1024)
                    original[index] = index & 255;
            }
}
