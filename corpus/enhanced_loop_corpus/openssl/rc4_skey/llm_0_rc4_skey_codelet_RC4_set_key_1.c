#include <stdio.h>

#include <inttypes.h>

extern int len;
extern  unsigned char *data;
extern unsigned int tmp;
extern int id1;
extern int id2;
extern unsigned int *d;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 256; i += 4) {
        for (int j = 0; j < 4; ++j) {
            tmp = d[(i + j)];
            id2 = (data[id1] + tmp + id2) & 255;
            if (++id1 == len)
                id1 = 0;
            d[(i + j)] = d[id2];
            d[id2] = tmp;
        }
    }
}
