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
for (i = 0; i < 128; i += 2) {
    unsigned int temp_sum1, temp_sum2;
    {
        tmp = d[i];
        temp_sum1 = data[id1] + tmp + id2;
        id2 = temp_sum1 & 255;
        if (++id1 == len)
            id1 = 0;
        d[i] = d[id2];
        d[id2] = tmp;
    }
    {
        tmp = d[i + 1];
        temp_sum2 = data[id1] + tmp + id2;
        id2 = temp_sum2 & 255;
        if (++id1 == len)
            id1 = 0;
        d[i + 1] = d[id2];
        d[id2] = tmp;
    }
}
}
