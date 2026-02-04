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
    unsigned int temp_vals[4];
    int indices[4];
    
    temp_vals[0] = d[(i + 0)];
    temp_vals[1] = d[(i + 1)];
    temp_vals[2] = d[(i + 2)];
    temp_vals[3] = d[(i + 3)];

    id2 = (data[id1] + temp_vals[0] + id2) & 255;
    if (++id1 == len) id1 = 0;
    indices[0] = id2;

    id2 = (data[id1] + temp_vals[1] + id2) & 255;
    if (++id1 == len) id1 = 0;
    indices[1] = id2;

    id2 = (data[id1] + temp_vals[2] + id2) & 255;
    if (++id1 == len) id1 = 0;
    indices[2] = id2;

    id2 = (data[id1] + temp_vals[3] + id2) & 255;
    if (++id1 == len) id1 = 0;
    indices[3] = id2;

    d[(i + 0)] = d[indices[0]];
    d[indices[0]] = temp_vals[0];
    d[(i + 1)] = d[indices[1]];
    d[indices[1]] = temp_vals[1];
    d[(i + 2)] = d[indices[2]];
    d[indices[2]] = temp_vals[2];
    d[(i + 3)] = d[indices[3]];
    d[indices[3]] = temp_vals[3];
}
}
