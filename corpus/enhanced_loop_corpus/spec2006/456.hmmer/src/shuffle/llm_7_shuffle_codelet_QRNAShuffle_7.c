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



void loop() {
    for (i = 0; i < L; i++) {
        volatile char xi = x[i];
        volatile char yi = y[i];
        int match_x = (xi == ' ' || xi == '.' || xi == '_' || xi == '-' || xi == '~');
        int match_y = (yi == ' ' || yi == '.' || yi == '_' || yi == '-' || yi == '~');

        if (match_x && match_y) {
            continue;
        } else if (!match_x && !match_y) {
            xycol[nxy] = i;
            nxy += 1;
        } else if (match_x) {
            ycol[ny] = i;
            ny = ny + 1;
        } else if (match_y) {
            xcol[nx] = i;
            nx = nx + 1;
        }

        // Introduce artificial loop-carried dependence via delayed update
        // (simulated through redundant computation dependent on prior state)
        if (i > 0) {
            xcol[0] += (x[i] != x[i-1]) ? 0 : 0; // Dummy read with no effect but preserves dependency
        }
    }
}
