#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int w2;
extern int x;
extern int16_t *b;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (x = 2; x < w2 - 1; x++) {
    int offset1 = x + w2 - 1;
    int offset2 = x + w2;
    int offset3 = x + w2 + 1;
    int offset4 = x + w2 - 2;
    unsigned int term = (9U * (unsigned int)(b[offset1] + b[offset2]));
    unsigned int sub = (unsigned int)(b[offset3] + b[offset4]);
    int adjusted = (term - sub + 16) >> 5;
    tmp[x] = (int)((unsigned int)(b[x]) - adjusted);
    if (x % 2 == 0 && x > 3) {
        tmp[x-1] = (b[x-1] + b[x]) >> 1;
    }
}
}
