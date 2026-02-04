#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern  uint8_t *scantable;
extern  int *qmat;
extern int last_non_zero;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i < 64; i += 2) {
    int j1 = scantable[i];
    int sign1 = ((block[j1]) >> 8 * sizeof (block[j1]) - 1);
    int level1 = (block[j1] ^ sign1) - sign1;
    level1 = level1 * qmat[j1] >> 18;
    block[j1] = (level1 ^ sign1) - sign1;
    if (level1)
        last_non_zero = i;

    if (i + 1 < 64) {
        int j2 = scantable[i + 1];
        int sign2 = ((block[j2]) >> 8 * sizeof (block[j2]) - 1);
        int level2 = (block[j2] ^ sign2) - sign2;
        level2 = level2 * qmat[j2] >> 18;
        block[j2] = (level2 ^ sign2) - sign2;
        if (level2)
            last_non_zero = i + 1;
    }
}
}
