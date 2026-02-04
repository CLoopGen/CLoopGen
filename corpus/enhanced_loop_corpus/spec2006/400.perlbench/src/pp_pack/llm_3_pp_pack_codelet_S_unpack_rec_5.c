#include <stdio.h>

#include <inttypes.h>

typedef unsigned char U8;

extern const char PL_uuemap[65];
extern char PL_uudmap[256];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int indices[] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30,
                     1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 32, 64};
    int num_elements = sizeof(indices) / sizeof(indices[0]);
    for (i = 0; i < num_elements; i += 1) {
        int idx = indices[i];
        if (idx < sizeof(PL_uuemap)) {
            PL_uudmap[(U8)PL_uuemap[idx]] = idx;
        }
    }
}
