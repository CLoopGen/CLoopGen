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
    int x_valid = ((x[i]) == ' ' || (x[i]) == '.' || (x[i]) == '_' || (x[i]) == '-' || (x[i]) == '~');
    int y_valid = ((y[i]) == ' ' || (y[i]) == '.' || (y[i]) == '_' || (y[i]) == '-' || (y[i]) == '~');

    if (x_valid && y_valid) {
        continue;
    }

    if (!x_valid && !y_valid) {
        xycol[nxy] = i;
        nxy++;
        continue;
    }

    if (x_valid) {
        ycol[ny] = i;
        ny++;
        continue;
    }

    if (y_valid) {
        xcol[nx] = i;
        nx++;
        continue;
    }
}
}
