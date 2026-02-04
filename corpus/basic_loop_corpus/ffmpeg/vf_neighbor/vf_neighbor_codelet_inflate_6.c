#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *p1;
extern int width;
extern int threshold;
extern  uint8_t *coordinates[];
extern int x;
extern int i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (x = 0; x < width; x++) {
    int sum = 0;
    int limit = ((p1[x] + threshold) > (255) ? (255) : (p1[x] + threshold));
    for (i = 0; i < 8; sum += *(coordinates[i++] + x))
        ;
    dst[x] = ((((sum / 8) > (p1[x]) ? (sum / 8) : (p1[x]))) > (limit) ? (limit) : (((sum / 8) > (p1[x]) ? (sum / 8) : (p1[x]))));
}

}
