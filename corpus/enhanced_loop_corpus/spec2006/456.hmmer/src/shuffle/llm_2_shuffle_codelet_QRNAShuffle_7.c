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
    // Variant 1: Strided Memory Access (stride of 2)
    for (i = 0; i < L; i += 2) {
        if (i >= L) break;

        int xi_val = (unsigned char)(x[i]);
        int yi_val = (unsigned char)(y[i]);

        int x_is_special = (xi_val == ' ' || xi_val == '.' || xi_val == '_' || xi_val == '-' || xi_val == '~');
        int y_is_special = (yi_val == ' ' || yi_val == '.' || yi_val == '_' || yi_val == '-' || yi_val == '~');

        if (x_is_special && y_is_special) {
            continue;
        } else if (!x_is_special && !y_is_special) {
            xycol[nxy] = i;
            nxy++;
        } else if (x_is_special) {
            ycol[ny] = i;
            ny++;
        } else if (y_is_special) {
            xcol[nx] = i;
            nx++;
        }
    }

    // Handle remaining odd index if L is odd
    if (L % 2 == 1) {
        i = L - 1;
        int xi_val = (unsigned char)(x[i]);
        int yi_val = (unsigned char)(y[i]);

        int x_is_special = (xi_val == ' ' || xi_val == '.' || xi_val == '_' || xi_val == '-' || xi_val == '~');
        int y_is_special = (yi_val == ' ' || yi_val == '.' || yi_val == '_' || yi_val == '-' || yi_val == '~');

        if (!(x_is_special && y_is_special)) {
            if (!x_is_special && !y_is_special) {
                xycol[nxy] = i;
                nxy++;
            } else if (x_is_special) {
                ycol[ny] = i;
                ny++;
            } else if (y_is_special) {
                xcol[nx] = i;
                nx++;
            }
        }
    }
}
