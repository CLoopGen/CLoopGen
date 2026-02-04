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
for (x = 1; x < w2; x++) {
    unsigned int term1 = 9U * b[x + w2];
    unsigned int term2 = 9U * b[x + w2 - 1];
    unsigned int term3 = b[x + w2 + 1];
    unsigned int term4 = b[x + w2 - 2];
    int adjusted = (int)((term1 + term2 - term3 - term4 + 16) >> 5);
    tmp[x] = b[x] - adjusted;
    
    if (x + 1 < w2 - 1) {
        int lookahead = (int)((9U * b[x + 1 + w2] + 9U * b[x + 1 + w2 - 1] - b[x + 1 + w2 + 1] - b[x + 1 + w2 - 2] + 16) >> 5);
        tmp[x + 1] = b[x + 1] - lookahead;
        x++;
    }
}
}
