#include <stdio.h>

#include <inttypes.h>

extern int num;
extern int i;
extern unsigned char ovec[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array
    int indices[8] = {7, 6, 5, 4, 3, 2, 1, 0}; // Reverse order access
    for (i = 0; i < 8; ++i) {
        int curr = indices[i];
        int next = (curr == 0) ? indices[i] : indices[i] - 1;
        ovec[curr] <<= num % 8;
        ovec[curr] |= ovec[next] >> (8 - num % 8);
    }
}
