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
    int temp_nxy = nxy;
    int temp_nx = nx;
    int temp_ny = ny;

    for (i = 0; i < L; i++) {
        char xi = x[i];
        char yi = y[i];
        int is_x_delim = (xi == ' ' || xi == '.' || xi == '_' || xi == '-' || xi == '~');
        int is_y_delim = (yi == ' ' || yi == '.' || yi == '_' || yi == '-' || yi == '~');

        if (is_x_delim && is_y_delim) {
            continue;
        } else if (!is_x_delim && !is_y_delim) {
            xycol[temp_nxy] = i;
            temp_nxy++;
        } else if (is_x_delim) {
            ycol[temp_ny] = i;
            temp_ny++;
        } else if (is_y_delim) {
            xcol[temp_nx] = i;
            temp_nx++;
        }
    }

    nxy = temp_nxy;
    nx = temp_nx;
    ny = temp_ny;
}
