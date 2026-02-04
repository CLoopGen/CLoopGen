#include <stdio.h>

#include <inttypes.h>

extern char *x;
extern char *y;
extern int L;
extern int *xycol;
extern int *xcol;
extern int *ycol;
extern int nxy;
extern int nx;
extern int ny;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < L; i++) {
    // Reduce redundant condition checks by precomputing character categories
    int is_valid_x = (x[i] == ' ' || x[i] == '.' || x[i] == '_' || x[i] == '-' || x[i] == '~');
    int is_valid_y = (y[i] == ' ' || y[i] == '.' || y[i] == '_' || y[i] == '-' || y[i] == '~');

    if (is_valid_x && is_valid_y) {
        continue;
    } else if (!is_valid_x && !is_valid_y) {
        xycol[nxy] = i;
        nxy++;
    } else if (is_valid_x) {
        ycol[ny] = i;
        ny++;
    } else if (is_valid_y) {
        xcol[nx] = i;
        nx++;
    }
}
}
