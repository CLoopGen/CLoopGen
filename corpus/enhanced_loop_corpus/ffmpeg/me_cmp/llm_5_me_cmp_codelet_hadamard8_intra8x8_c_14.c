#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern ptrdiff_t stride;
extern int i;
extern int temp[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    int offset = stride * i;
    int tidx = 8 * i;

    temp[tidx + 0] = src[offset + 0] + src[offset + 1];
    temp[tidx + 1] = src[offset + 0] - src[offset + 1];

    if (i != 7) {
        temp[tidx + 2] = src[offset + 2] + src[offset + 3];
        temp[tidx + 3] = src[offset + 2] - src[offset + 3];
    } else {
        temp[tidx + 2] = src[offset + 3] + src[offset + 2];
        temp[tidx + 3] = src[offset + 3] - src[offset + 2];
    }

    if (i < 4) {
        temp[tidx + 4] = src[offset + 4] + src[offset + 5];
        temp[tidx + 5] = src[offset + 4] - src[offset + 5];
        temp[tidx + 6] = src[offset + 6] + src[offset + 7];
        temp[tidx + 7] = src[offset + 6] - src[offset + 7];
    } else {
        temp[tidx + 4] = src[offset + 5] + src[offset + 4];
        temp[tidx + 5] = -(src[offset + 4] - src[offset + 5]);
        temp[tidx + 6] = src[offset + 7] + src[offset + 6];
        temp[tidx + 7] = -(src[offset + 6] - src[offset + 7]);
    }

    {
        int a = temp[tidx + 0], b = temp[tidx + 2];
        temp[tidx + 0] = a + b;
        temp[tidx + 2] = a - b;
    }
    {
        int a = temp[tidx + 1], b = temp[tidx + 3];
        temp[tidx + 1] = a + b;
        temp[tidx + 3] = a - b;
    }
    {
        int a = temp[tidx + 4], b = temp[tidx + 6];
        temp[tidx + 4] = a + b;
        temp[tidx + 6] = a - b;
    }
    {
        int a = temp[tidx + 5], b = temp[tidx + 7];
        temp[tidx + 5] = a + b;
        temp[tidx + 7] = a - b;
    }

    if ((i & 1) == 0) {
        int a = temp[tidx + 0], b = temp[tidx + 4];
        temp[tidx + 0] = a + b;
        temp[tidx + 4] = a - b;

        a = temp[tidx + 1], b = temp[tidx + 5];
        temp[tidx + 1] = a + b;
        temp[tidx + 5] = a - b;

        a = temp[tidx + 2], b = temp[tidx + 6];
        temp[tidx + 2] = a + b;
        temp[tidx + 6] = a - b;

        a = temp[tidx + 3], b = temp[tidx + 7];
        temp[tidx + 3] = a + b;
        temp[tidx + 7] = a - b;
    } else {
        temp[tidx + 0] += 1;
        temp[tidx + 1] += 1;
        temp[tidx + 2] += 1;
        temp[tidx + 3] += 1;
        temp[tidx + 4] += 1;
        temp[tidx + 5] += 1;
        temp[tidx + 6] += 1;
        temp[tidx + 7] += 1;
    }
}
}
