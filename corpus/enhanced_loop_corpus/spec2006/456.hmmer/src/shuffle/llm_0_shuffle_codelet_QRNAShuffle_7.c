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
for (i = 0; i < L; i += 2) {
    if (i + 1 < L) {
        // Process two elements per iteration
        for (int j = 0; j < 2; j++) {
            int idx = i + j;
            if (((x[idx]) == ' ' || (x[idx]) == '.' || (x[idx]) == '_' || (x[idx]) == '-' || (x[idx]) == '~') && ((y[idx]) == ' ' || (y[idx]) == '.' || (y[idx]) == '_' || (y[idx]) == '-' || (y[idx]) == '~')) {
                continue;
            } else if (!((x[idx]) == ' ' || (x[idx]) == '.' || (x[idx]) == '_' || (x[idx]) == '-' || (x[idx]) == '~') && !((y[idx]) == ' ' || (y[idx]) == '.' || (y[idx]) == '_' || (y[idx]) == '-' || (y[idx]) == '~')) {
                xycol[nxy] = idx;
                nxy++;
            } else if (((x[idx]) == ' ' || (x[idx]) == '.' || (x[idx]) == '_' || (x[idx]) == '-' || (x[idx]) == '~')) {
                ycol[ny] = idx;
                ny++;
            } else if (((y[idx]) == ' ' || (y[idx]) == '.' || (y[idx]) == '_' || (y[idx]) == '-' || (y[idx]) == '~')) {
                xcol[nx] = idx;
                nx++;
            }
        }
    } else {
        // Handle last element if L is odd
        int idx = i;
        if (((x[idx]) == ' ' || (x[idx]) == '.' || (x[idx]) == '_' || (x[idx]) == '-' || (x[idx]) == '~') && ((y[idx]) == ' ' || (y[idx]) == '.' || (y[idx]) == '_' || (y[idx]) == '-' || (y[idx]) == '~')) {
            continue;
        } else if (!((x[idx]) == ' ' || (x[idx]) == '.' || (x[idx]) == '_' || (x[idx]) == '-' || (x[idx]) == '~') && !((y[idx]) == ' ' || (y[idx]) == '.' || (y[idx]) == '_' || (y[idx]) == '-' || (y[idx]) == '~')) {
            xycol[nxy] = idx;
            nxy++;
        } else if (((x[idx]) == ' ' || (x[idx]) == '.' || (x[idx]) == '_' || (x[idx]) == '-' || (x[idx]) == '~')) {
            ycol[ny] = idx;
            ny++;
        } else if (((y[idx]) == ' ' || (y[idx]) == '.' || (y[idx]) == '_' || (y[idx]) == '-' || (y[idx]) == '~')) {
            xcol[nx] = idx;
            nx++;
        }
    }
}
}
