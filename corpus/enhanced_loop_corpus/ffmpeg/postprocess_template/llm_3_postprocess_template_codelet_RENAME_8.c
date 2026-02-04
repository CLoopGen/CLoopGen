#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int a;
extern int b;
extern int c;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int values[3];
    int indices[] = {0, 1, 2, 0, 1, 2, 0, 1}; // Indirect access pattern
    for (x = 0; x < 2; x++) {
        values[0] = a;
        values[1] = b;
        values[2] = c;

        for (int i = 0; i < 8; i += 3) {
            int idx_a = indices[i];
            int idx_b = indices[i+1];
            int idx_c = indices[i+2];

            values[idx_a] = (values[idx_a] & values[idx_c]) + 
                            ((((values[idx_a] ^ values[idx_c]) & 4278124286UL) >> 1));
            values[idx_b] = (values[idx_a] & values[idx_b]) + 
                            ((((values[idx_a] ^ values[idx_b]) & 4278124286UL) >> 1));
            values[idx_c] = (values[idx_b] & values[idx_c]) + 
                            ((((values[idx_b] ^ values[idx_c]) & 4278124286UL) >> 1));
        }

        a = values[0];
        b = values[1];
        c = values[2];
    }
}
