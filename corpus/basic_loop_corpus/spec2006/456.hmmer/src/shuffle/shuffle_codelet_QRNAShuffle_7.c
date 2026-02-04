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
    if (((x[i]) == ' ' || (x[i]) == '.' || (x[i]) == '_' || (x[i]) == '-' || (x[i]) == '~') && ((y[i]) == ' ' || (y[i]) == '.' || (y[i]) == '_' || (y[i]) == '-' || (y[i]) == '~')) {
        continue;
    } else if (!((x[i]) == ' ' || (x[i]) == '.' || (x[i]) == '_' || (x[i]) == '-' || (x[i]) == '~') && !((y[i]) == ' ' || (y[i]) == '.' || (y[i]) == '_' || (y[i]) == '-' || (y[i]) == '~')) {
        xycol[nxy] = i;
        nxy++;
    } else if (((x[i]) == ' ' || (x[i]) == '.' || (x[i]) == '_' || (x[i]) == '-' || (x[i]) == '~')) {
        ycol[ny] = i;
        ny++;
    } else if (((y[i]) == ' ' || (y[i]) == '.' || (y[i]) == '_' || (y[i]) == '-' || (y[i]) == '~')) {
        xcol[nx] = i;
        nx++;
    }
}

}
