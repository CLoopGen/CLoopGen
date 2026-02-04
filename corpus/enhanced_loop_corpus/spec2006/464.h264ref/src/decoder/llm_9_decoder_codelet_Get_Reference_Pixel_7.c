#include <stdio.h>

#include <inttypes.h>

extern unsigned short **imY;
extern int x_pos;
extern int x;
extern int maxold_x;
extern int result;
extern int pres_x;
extern int pres_y;
extern  int COEF[6];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int offset;
    for (x = -2; x <= 3; x++) {
        offset = x + 2;
        pres_x = x_pos + x;
        if (pres_x > maxold_x) pres_x = maxold_x;
        if (pres_x < 0) pres_x = 0;
        result += imY[pres_y][pres_x] * COEF[offset];
        result -= imY[pres_y][pres_x] * (COEF[offset] >> 2); // Increased arithmetic intensity
    }
}
