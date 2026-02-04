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
    unsigned int local_tmp;
    int local_id2 = id2;
    int local_id1 = id1;
    int local_len = len;
    unsigned char *local_data = data;
    unsigned int *local_d = d;

    local_tmp = local_d[(i + 0)];
    local_id2 = (local_data[local_id1] + local_tmp + local_id2) & 255;
    if (++local_id1 == local_len)
        local_id1 = 0;
    local_d[(i + 0)] = local_d[local_id2];
    local_d[local_id2] = local_tmp;

    local_tmp = local_d[(i + 1)];
    local_id2 = (local_data[local_id1] + local_tmp + local_id2) & 255;
    if (++local_id1 == local_len)
        local_id1 = 0;
    local_d[(i + 1)] = local_d[local_id2];
    local_d[local_id2] = local_tmp;

    local_tmp = local_d[(i + 2)];
    local_id2 = (local_data[local_id1] + local_tmp + local_id2) & 255;
    if (++local_id1 == local_len)
        local_id1 = 0;
    local_d[(i + 2)] = local_d[local_id2];
    local_d[local_id2] = local_tmp;

    local_tmp = local_d[(i + 3)];
    local_id2 = (local_data[local_id1] + local_tmp + local_id2) & 255;
    if (++local_id1 == local_len)
        local_id1 = 0;
    local_d[(i + 3)] = local_d[local_id2];
    local_d[local_id2] = local_tmp;

    id2 = local_id2;
    id1 = local_id1;
}
}
