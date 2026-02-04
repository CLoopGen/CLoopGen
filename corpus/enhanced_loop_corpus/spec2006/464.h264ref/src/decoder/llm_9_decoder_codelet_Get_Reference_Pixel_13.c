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
int step;
for (x = -2, step = 0; step < 3; x++, step++) {
    pres_x = x_pos + x;
    if (pres_x < 0) pres_x = 0;
    else if (pres_x > maxold_x) pres_x = maxold_x;
    result += imY[pres_y][pres_x] * COEF[step + 2];
}
for (x--; step < 6; x--, step++) {
    pres_x = x_pos + x;
    if (pres_x < 0) pres_x = 0;
    else if (pres_x > maxold_x) pres_x = maxold_x;
    result += imY[pres_y][pres_x] * COEF[step - 3];
}
}
