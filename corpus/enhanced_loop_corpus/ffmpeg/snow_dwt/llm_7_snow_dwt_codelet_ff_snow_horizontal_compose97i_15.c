#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

extern IDWTELEM *b;
extern IDWTELEM *temp;
extern int width;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
IDWTELEM prev_b = 0;
for (x = 2; x < width - 1; x += 2) {
    IDWTELEM computed_b = temp[x] + ((4 * temp[x] + temp[x - 1] + temp[x + 1] + 8) >> 4);
    b[x] = computed_b;
    b[x - 1] = temp[x - 1] + ((3 * (prev_b + computed_b)) >> 1);
    prev_b = computed_b;
}
}
