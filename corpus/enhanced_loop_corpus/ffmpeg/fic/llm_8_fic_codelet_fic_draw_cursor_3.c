#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *ptr;
extern uint8_t planes[4][1024];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 256; i++) {
    uint8_t r = ptr[0], g = ptr[1], b = ptr[2], a = ptr[3];
    int y = (25 * r + 129 * g + 66 * b) / 255 + 16;
    int u = (-38 * r + 112 * g - 74 * b) / 255 + 128;
    int v = (-18 * r + 112 * g - 94 * b) / 255 + 128;
    planes[0][i*4+0] = (y > 255) ? 255 : (y < 0) ? 0 : y;
    planes[1][i*4+0] = (u > 255) ? 255 : (u < 0) ? 0 : u;
    planes[2][i*4+0] = (v > 255) ? 255 : (v < 0) ? 0 : v;
    planes[3][i*4+0] = a;
    
    r = ptr[4], g = ptr[5], b = ptr[6], a = ptr[7];
    y = (25 * r + 129 * g + 66 * b) / 255 + 16;
    u = (-38 * r + 112 * g - 74 * b) / 255 + 128;
    v = (-18 * r + 112 * g - 94 * b) / 255 + 128;
    planes[0][i*4+1] = (y > 255) ? 255 : (y < 0) ? 0 : y;
    planes[1][i*4+1] = (u > 255) ? 255 : (u < 0) ? 0 : u;
    planes[2][i*4+1] = (v > 255) ? 255 : (v < 0) ? 0 : v;
    planes[3][i*4+1] = a;
    
    r = ptr[8], g = ptr[9], b = ptr[10], a = ptr[11];
    y = (25 * r + 129 * g + 66 * b) / 255 + 16;
    u = (-38 * r + 112 * g - 74 * b) / 255 + 128;
    v = (-18 * r + 112 * g - 94 * b) / 255 + 128;
    planes[0][i*4+2] = (y > 255) ? 255 : (y < 0) ? 0 : y;
    planes[1][i*4+2] = (u > 255) ? 255 : (u < 0) ? 0 : u;
    planes[2][i*4+2] = (v > 255) ? 255 : (v < 0) ? 0 : v;
    planes[3][i*4+2] = a;
    
    r = ptr[12], g = ptr[13], b = ptr[14], a = ptr[15];
    y = (25 * r + 129 * g + 66 * b) / 255 + 16;
    u = (-38 * r + 112 * g - 74 * b) / 255 + 128;
    v = (-18 * r + 112 * g - 94 * b) / 255 + 128;
    planes[0][i*4+3] = (y > 255) ? 255 : (y < 0) ? 0 : y;
    planes[1][i*4+3] = (u > 255) ? 255 : (u < 0) ? 0 : u;
    planes[2][i*4+3] = (v > 255) ? 255 : (v < 0) ? 0 : v;
    planes[3][i*4+3] = a;
    
    ptr += 16;
}
}
