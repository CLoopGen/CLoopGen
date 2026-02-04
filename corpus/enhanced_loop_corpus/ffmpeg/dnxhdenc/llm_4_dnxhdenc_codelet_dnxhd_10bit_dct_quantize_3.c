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
for (i = 1; i < 64; ++i) {
    int j = scantable[i];
    int sign = ((block[j]) >> 8 * sizeof (block[j]) - 1);
    int level = (block[j] ^ sign) - sign;
    level = level * qmat[j] >> 18;
    block[j] = (level ^ sign) - sign;
}
}
