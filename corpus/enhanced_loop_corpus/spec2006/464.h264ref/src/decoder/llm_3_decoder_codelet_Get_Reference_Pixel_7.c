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
    // Variant 2: Strided Memory Access with increased stride (access every second element, adjusted logic)
    int stride = 2;
    int start = -2 * stride; // Scale initial offset by stride
    int temp_result = 0;
    for (int step = 0; step < 6; step++) {
        int logical_x = -2 + step; // Original x value being simulated
        int physical_x = x_pos + logical_x * stride; // Apply strided access
        int pres_x = (physical_x < 0) ? 0 : ((physical_x > maxold_x) ? maxold_x : physical_x);
        temp_result += imY[pres_y][pres_x] * COEF[step];
    }
    result += temp_result;
}
