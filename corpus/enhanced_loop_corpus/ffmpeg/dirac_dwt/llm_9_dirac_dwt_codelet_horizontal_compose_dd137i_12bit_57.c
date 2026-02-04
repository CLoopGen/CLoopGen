#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int w2;
extern int x;
extern int32_t *b;
extern int32_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 1; x < w2 - 2; x++) {
        unsigned int term1 = (unsigned int)(b[x]);
        unsigned int term2 = (9U * b[x + w2 - 1]);
        unsigned int term3 = (9U * b[x + w2]);
        unsigned int term4 = (unsigned int)(b[x + w2 + 1]);
        unsigned int term5 = (unsigned int)(b[x + w2 - 2]);
        int adjusted = ((term2 + term3 - term4 - term5 + 16) >> 5);
        tmp[x] = (int)(term1 - adjusted);
        if (x + 1 < w2 - 2) {
            tmp[x + 1] = (int)(((unsigned int)(b[x + 1]) - ((9U * b[x + 1 + w2 - 1] + 9U * b[x + 1 + w2] - b[x + 1 + w2 + 1] - b[x + 1 + w2 - 2] + 16) >> 5)));
            x++;
        }
    }
}
