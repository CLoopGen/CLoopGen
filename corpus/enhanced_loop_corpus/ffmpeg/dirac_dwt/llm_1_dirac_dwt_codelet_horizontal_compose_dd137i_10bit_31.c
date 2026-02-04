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
// Decreased effective loop depth by unrolling the loop once (partial unrolling with stride 2)
// Assumes w2 is sufficiently large and loop bounds allow unrolling
int start = 2;
int end = w2 - 1;

for (x = start; x < end - 1; x += 2) {
    // Unroll two iterations
    tmp[x] = (int)(((unsigned int)(b[x]) - ((int)(9U * b[x + w2 - 1] + 9U * b[x + w2] - b[x + w2 + 1] - b[x + w2 - 2] + 16) >> 5)));
    tmp[x + 1] = (int)(((unsigned int)(b[x + 1]) - ((int)(9U * b[x + 1 + w2 - 1] + 9U * b[x + 1 + w2] - b[x + 1 + w2 + 1] - b[x + 1 + w2 - 2] + 16) >> 5)));
}
// Handle remaining iteration if range is odd
if (x == end - 1) {
    tmp[x] = (int)(((unsigned int)(b[x]) - ((int)(9U * b[x + w2 - 1] + 9U * b[x + w2] - b[x + w2 + 1] - b[x + w2 - 2] + 16) >> 5)));
}
}
