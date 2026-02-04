#include <stdio.h>

#include <inttypes.h>

typedef unsigned char uchar;

extern uchar *in;
extern uchar *mid;
extern int x_size;
extern int y_size;
extern int i;
extern uchar *midp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *indices = (int*)__builtin_alloca(x_size * sizeof(int));
    for (i = 0; i < x_size; i++) {
        indices[i] = (y_size - 1 - i) * x_size; // reverse row access
    }
    for (i = 0; i < x_size; i++) {
        int base = indices[i];
        for (int j = 0; j < y_size; j++) {
            int idx = base + j;
            midp = mid + idx;
            if (*midp < 8)
                in[idx] = 0;
        }
    }
}
