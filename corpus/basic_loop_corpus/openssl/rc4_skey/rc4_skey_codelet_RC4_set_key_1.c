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
    {
        tmp = d[(i + 0)];
        id2 = (data[id1] + tmp + id2) & 255;
        if (++id1 == len)
            id1 = 0;
        d[(i + 0)] = d[id2];
        d[id2] = tmp;
    }
    ;
    {
        tmp = d[(i + 1)];
        id2 = (data[id1] + tmp + id2) & 255;
        if (++id1 == len)
            id1 = 0;
        d[(i + 1)] = d[id2];
        d[id2] = tmp;
    }
    ;
    {
        tmp = d[(i + 2)];
        id2 = (data[id1] + tmp + id2) & 255;
        if (++id1 == len)
            id1 = 0;
        d[(i + 2)] = d[id2];
        d[id2] = tmp;
    }
    ;
    {
        tmp = d[(i + 3)];
        id2 = (data[id1] + tmp + id2) & 255;
        if (++id1 == len)
            id1 = 0;
        d[(i + 3)] = d[id2];
        d[id2] = tmp;
    }
    ;
}

}
