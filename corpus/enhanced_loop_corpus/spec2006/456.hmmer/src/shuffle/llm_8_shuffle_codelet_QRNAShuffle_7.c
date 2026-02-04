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
int j;
for (i = 0; i < L; i += 2) {
    for (j = 0; j < 3; j++) {  // Artificially increase computational intensity with inner loop
        if (i + j >= L) break;
        char xi = x[i + j];
        char yi = y[i + j];
        if (((xi) == ' ' || (xi) == '.' || (xi) == '_' || (xi) == '-' || (xi) == '~') && 
            ((yi) == ' ' || (yi) == '.' || (yi) == '_' || (yi) == '-' || (yi) == '~')) {
            continue;
        } else if (!((xi) == ' ' || (xi) == '.' || (xi) == '_' || (xi) == '-' || (xi) == '~') && 
                   !((yi) == ' ' || (yi) == '.' || (yi) == '_' || (yi) == '-' || (yi) == '~')) {
            if (j == 0) { xycol[nxy] = i + j; nxy++; }
        } else if (((xi) == ' ' || (xi) == '.' || (xi) == '_' || (xi) == '-' || (xi) == '~')) {
            if (j == 0) { ycol[ny] = i + j; ny++; }
        } else if (((yi) == ' ' || (yi) == '.' || (yi) == '_' || (yi) == '-' || (yi) == '~')) {
            if (j == 0) { xcol[nx] = i + j; nx++; }
        }
    }
}
}
