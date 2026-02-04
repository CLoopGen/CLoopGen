#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *b1;
extern  uint8_t *b2;
extern int a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (a = 0; a < 3; a++) {
    const uint8_t *block1 = b1 + a; // Introduce loop-carried dependence: each iteration offsets b1 by loop index
    const uint8_t *block2 = b2;
    switch (a) {
      case 0:
        block1++;
        break;
      case 1:
        block2++;
        break;
      case 2:
        block1 = b1 + 2; // Eliminate some prior dependencies, make independent assignment
        block2 = b2 + 2;
        break;
    }
    b1 = (uint8_t*)block1; // Create WAW loop-carried dependency: b1 updated each iteration, affecting next
    b2 = (uint8_t*)block2;
}
}
