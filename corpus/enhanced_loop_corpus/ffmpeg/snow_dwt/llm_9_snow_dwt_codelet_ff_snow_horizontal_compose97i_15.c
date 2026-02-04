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
for (x = 2; x < width - 3; x += 4) {
    IDWTELEM tx_m1 = temp[x - 1];
    IDWTELEM tx     = temp[x];
    IDWTELEM tx_p1 = temp[x + 1];
    IDWTELEM tx_p2 = temp[x + 2];

    int interp_x   = (4 * tx + tx_m1 + tx_p1 + 8) >> 4;
    int interp_xp2 = (4 * tx_p2 + tx_p1 + temp[x + 3] + 8) >> 4;

    b[x]       = tx + interp_x;
    b[x + 2]   = tx_p2 + interp_xp2;

    b[x - 1]   = tx_m1 + ((3 * (b[x - 2] + b[x])) >> 1);
    b[x + 1]   = tx_p1 + ((3 * (b[x] + b[x + 2])) >> 1);
}
}
