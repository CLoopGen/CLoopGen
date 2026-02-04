#include <stdio.h>

#include <inttypes.h>

extern unsigned short **imY;
extern int y_pos;
extern int x_pos;
extern int x;
extern int y;
extern int maxold_x;
extern int maxold_y;
extern int result;
extern int pres_x;
extern int pres_y;
extern int tmp_res[6];
extern  int COEF[6];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (x = 0; x < 6; x++) {
    result = 0;
    int mapped_x = x - 2;
    pres_x = x_pos + mapped_x;
    pres_x = (pres_x < 0) ? 0 : ((pres_x < maxold_x) ? pres_x : maxold_x - 1);
    for (int idx = 0; idx < 6; idx++) {
        int dy = idx - 2;
        int py = y_pos + dy;
        py = (py < 0) ? 0 : ((py < maxold_y) ? py : maxold_y - 1);
        result += imY[py][pres_x] * COEF[idx];
    }
    tmp_res[x] = result;
}
}
