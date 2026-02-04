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
// Unroll the original loop completely since max depth is reduced by eliminating the loop structure entirely
// This variant replaces the loop with direct unrolled iterations (i=0 to i=7)

int i;

i = 0;
temp[8 * i + 0] = (src[stride * i + 0]) + (src[stride * i + 1]);
temp[8 * i + 1] = (src[stride * i + 0]) - (src[stride * i + 1]);
temp[8 * i + 2] = (src[stride * i + 2]) + (src[stride * i + 3]);
temp[8 * i + 3] = (src[stride * i + 2]) - (src[stride * i + 3]);
temp[8 * i + 4] = (src[stride * i + 4]) + (src[stride * i + 5]);
temp[8 * i + 5] = (src[stride * i + 4]) - (src[stride * i + 5]);
temp[8 * i + 6] = (src[stride * i + 6]) + (src[stride * i + 7]);
temp[8 * i + 7] = (src[stride * i + 6]) - (src[stride * i + 7]);

{
    int a, b;
    a = temp[8 * i + 0]; b = temp[8 * i + 2];
    temp[8 * i + 0] = a + b; temp[8 * i + 2] = a - b;
}
{
    int a, b;
    a = temp[8 * i + 1]; b = temp[8 * i + 3];
    temp[8 * i + 1] = a + b; temp[8 * i + 3] = a - b;
}
{
    int a, b;
    a = temp[8 * i + 4]; b = temp[8 * i + 6];
    temp[8 * i + 4] = a + b; temp[8 * i + 6] = a - b;
}
{
    int a, b;
    a = temp[8 * i + 5]; b = temp[8 * i + 7];
    temp[8 * i + 5] = a + b; temp[8 * i + 7] = a - b;
}
{
    int a, b;
    a = temp[8 * i + 0]; b = temp[8 * i + 4];
    temp[8 * i + 0] = a + b; temp[8 * i + 4] = a - b;
}
{
    int a, b;
    a = temp[8 * i + 1]; b = temp[8 * i + 5];
    temp[8 * i + 1] = a + b; temp[8 * i + 5] = a - b;
}
{
    int a, b;
    a = temp[8 * i + 2]; b = temp[8 * i + 6];
    temp[8 * i + 2] = a + b; temp[8 * i + 6] = a - b;
}
{
    int a, b;
    a = temp[8 * i + 3]; b = temp[8 * i + 7];
    temp[8 * i + 3] = a + b; temp[8 * i + 7] = a - b;
}

i = 1;
temp[8 * i + 0] = (src[stride * i + 0]) + (src[stride * i + 1]);
temp[8 * i + 1] = (src[stride * i + 0]) - (src[stride * i + 1]);
temp[8 * i + 2] = (src[stride * i + 2]) + (src[stride * i + 3]);
temp[8 * i + 3] = (src[stride * i + 2]) - (src[stride * i + 3]);
temp[8 * i + 4] = (src[stride * i + 4]) + (src[stride * i + 5]);
temp[8 * i + 5] = (src[stride * i + 4]) - (src[stride * i + 5]);
temp[8 * i + 6] = (src[stride * i + 6]) + (src[stride * i + 7]);
temp[8 * i + 7] = (src[stride * i + 6]) - (src[stride * i + 7]);

{
    int a, b;
    a = temp[8 * i + 0]; b = temp[8 * i + 2];
    temp[8 * i + 0] = a + b; temp[8 * i + 2] = a - b;
}
{
    int a, b;
    a = temp[8 * i + 1]; b = temp[8 * i + 3];
    temp[8 * i + 1] = a + b; temp[8 * i + 3] = a - b;
}
{
    int a, b;
    a = temp[8 * i + 4]; b = temp[8 * i + 6];
    temp[8 * i + 4] = a + b; temp[8 * i + 6] = a - b;
}
{
    int a, b;
    a = temp[8 * i + 5]; b = temp[8 * i + 7];
    temp[8 * i + 5] = a + b; temp[8 * i + 7] = a - b;
}
{
    int a, b;
    a = temp[8 * i + 0]; b = temp[8 * i + 4];
    temp[8 * i + 0] = a + b; temp[8 * i + 4] = a - b;
}
{
    int a, b;
    a = temp[8 * i + 1]; b = temp[8 * i + 5];
    temp[8 * i + 1] = a + b; temp[8 * i + 5] = a - b;
}
{
    int a, b;
    a = temp[8 * i + 2]; b = temp[8 * i + 6];
    temp[8 * i + 2] = a + b; temp[8 * i + 6] = a - b;
}
{
    int a, b;
    a = temp[8 * i + 3]; b = temp[8 * i + 7];
    temp[8 * i + 3] = a + b; temp[8 * i + 7] = a - b;
}

i = 2;
temp[8 * i + 0] = (src[stride * i + 0]) + (src[stride * i + 1]);
temp[8 * i + 1] = (src[stride * i + 0]) - (src[stride * i + 1]);
temp[8 * i + 2] = (src[stride * i + 2]) + (src[stride * i + 3]);
temp[8 * i + 3] = (src[stride * i + 2]) - (src[stride * i + 3]);
temp[8 * i + 4] = (src[stride * i + 4]) + (src[stride * i + 5]);
temp[8 * i + 5] = (src[stride * i + 4]) - (src[stride * i + 5]);
temp[8 * i + 6] = (src[stride * i + 6]) + (src[stride * i + 7]);
temp[8 * i + 7] = (src[stride * i + 6]) - (src[stride * i + 7]);

{
    int a, b;
    a = temp[8 * i + 0]; b = temp[8 * i + 2];
    temp[8 * i + 0] = a + b; temp[8 * i + 2] = a - b;
}
{
    int a, b;
    a = temp[8 * i + 1]; b = temp[8 * i + 3];
    temp[8 * i + 1] = a + b; temp[8 * i + 3] = a - b;
}
{
    int a, b;
    a = temp[8 * i + 4]; b = temp[8 * i + 6];
    temp[8 * i + 4] = a + b; temp[8 * i + 6] = a - b;
}
{
    int a, b;
    a = temp[8 * i + 5]; b = temp[8 * i + 7];
    temp[8 * i + 5] = a + b; temp[8 * i + 7] = a - b;
}
{
    int a, b;
    a = temp[8 * i + 0]; b = temp[8 * i + 4];
    temp[8 * i + 0] = a + b; temp[8 * i + 4] = a - b;
}
{
    int a, b;
    a = temp[8 * i + 1]; b = temp[8 * i + 5];
    temp[8 * i + 1] = a + b; temp[8 * i + 5] = a - b;
}
{
    int a, b;
    a = temp[8 * i + 2]; b = temp[8 * i + 6];
    temp[8 * i + 2] = a + b; temp[8 * i + 6] = a - b;
}
{
    int a, b;
    a = temp[8 * i + 3]; b = temp[8 * i + 7];
    temp[8 * i + 3] = a + b; temp[8 * i + 7] = a - b;
}

i = 3;
temp[8 * i + 0] = (src[stride * i + 0]) + (src[stride * i + 1]);
temp[8 * i + 1] = (src[stride * i + 0]) - (src[stride * i + 1]);
temp[8 * i + 2] = (src[stride * i + 2]) + (src[stride * i + 3]);
temp[8 * i + 3] = (src[stride * i + 2]) - (src[stride * i + 3]);
temp[8 * i + 4] = (src[stride * i + 4]) + (src[stride * i + 5]);
temp[8 * i + 5] = (src[stride * i + 4]) - (src[stride * i + 5]);
temp[8 * i + 6] = (src[stride * i + 6]) + (src[stride * i + 7]);
temp[8 * i + 7] = (src[stride * i + 6]) - (src[stride * i + 7]);

{
    int a, b;
    a = temp[8 * i + 0]; b = temp[8 * i + 2];
    temp[8 * i + 0] = a + b; temp[8 * i + 2] = a - b;
}
{
    int a, b;
    a = temp[8 * i + 1]; b = temp[8 * i + 3];
    temp[8 * i + 1] = a + b; temp[8 * i + 3] = a - b;
}
{
    int a, b;
    a = temp[8 * i + 4]; b = temp[8 * i + 6];
    temp[8 * i + 4] = a + b; temp[8 * i + 6] = a - b;
}
{
    int a, b;
    a = temp[8 * i + 5]; b = temp[8 * i + 7];
    temp[8 * i + 5] = a + b; temp[8 * i + 7] = a - b;
}
{
    int a, b;
    a = temp[8 * i + 0]; b = temp[8 * i + 4];
    temp[8 * i + 0] = a + b; temp[8 * i + 4] = a - b;
}
{
    int a, b;
    a = temp[8 * i + 1]; b = temp[8 * i + 5];
    temp[8 * i + 1] = a + b; temp[8 * i + 5] = a - b;
}
{
    int a, b;
    a = temp[8 * i + 2]; b = temp[8 * i + 6];
    temp[8 * i + 2] = a + b; temp[8 * i + 6] = a - b;
}
{
    int a, b;
    a = temp[8 * i + 3]; b = temp[8 * i + 7];
    temp[8 * i + 3] = a + b; temp[8 * i + 7] = a - b;
}

i = 4;
temp[8 * i + 0] = (src[stride * i + 0]) + (src[stride * i + 1]);
temp[8 * i + 1] = (src[stride * i + 0]) - (src[stride * i + 1]);
temp[8 * i + 2] = (src[stride * i + 2]) + (src[stride * i + 3]);
temp[8 * i + 3] = (src[stride * i + 2]) - (src[stride * i + 3]);
temp[8 * i + 4] = (src[stride * i + 4]) + (src[stride * i + 5]);
temp[8 * i + 5] = (src[stride * i + 4]) - (src[stride * i + 5]);
temp[8 * i + 6] = (src[stride * i + 6]) + (src[stride * i + 7]);
temp[8 * i + 7] = (src[stride * i + 6]) - (src[stride * i + 7]);

{
    int a, b;
    a = temp[8 * i + 0]; b = temp[8 * i + 2];
    temp[8 * i + 0] = a + b; temp[8 * i + 2] = a - b;
}
{
    int a, b;
    a = temp[8 * i + 1]; b = temp[8 * i + 3];
    temp[8 * i + 1] = a + b; temp[8 * i + 3] = a - b;
}
{
    int a, b;
    a = temp[8 * i + 4]; b = temp[8 * i + 6];
    temp[8 * i + 4] = a + b; temp[8 * i + 6] = a - b;
}
{
    int a, b;
    a = temp[8 * i + 5]; b = temp[8 * i + 7];
    temp[8 * i + 5] = a + b; temp[8 * i + 7] = a - b;
}
{
    int a, b;
    a = temp[8 * i + 0]; b = temp[8 * i + 4];
    temp[8 * i + 0] = a + b; temp[8 * i + 4] = a - b;
}
{
    int a, b;
    a = temp[8 * i + 1]; b = temp[8 * i + 5];
    temp[8 * i + 1] = a + b; temp[8 * i + 5] = a - b;
}
{
    int a, b;
    a = temp[8 * i + 2]; b = temp[8 * i + 6];
    temp[8 * i + 2] = a + b; temp[8 * i + 6] = a - b;
}
{
    int a, b;
    a = temp[8 * i + 3]; b = temp[8 * i + 7];
    temp[8 * i + 3] = a + b; temp[8 * i + 7] = a - b;
}

i = 5;
temp[8 * i + 0] = (src[stride * i + 0]) + (src[stride * i + 1]);
temp[8 * i + 1] = (src[stride * i + 0]) - (src[stride * i + 1]);
temp[8 * i + 2] = (src[stride * i + 2]) + (src[stride * i + 3]);
temp[8 * i + 3] = (src[stride * i + 2]) - (src[stride * i + 3]);
temp[8 * i + 4] = (src[stride * i + 4]) + (src[stride * i + 5]);
temp[8 * i + 5] = (src[stride * i + 4]) - (src[stride * i + 5]);
temp[8 * i + 6] = (src[stride * i + 6]) + (src[stride * i + 7]);
temp[8 * i + 7] = (src[stride * i + 6]) - (src[stride * i + 7]);

{
    int a, b;
    a = temp[8 * i + 0]; b = temp[8 * i + 2];
    temp[8 * i + 0] = a + b; temp[8 * i + 2] = a - b;
}
{
    int a, b;
    a = temp[8 * i + 1]; b = temp[8 * i + 3];
    temp[8 * i + 1] = a + b; temp[8 * i + 3] = a - b;
}
{
    int a, b;
    a = temp[8 * i + 4]; b = temp[8 * i + 6];
    temp[8 * i + 4] = a + b; temp[8 * i + 6] = a - b;
}
{
    int a, b;
    a = temp[8 * i + 5]; b = temp[8 * i + 7];
    temp[8 * i + 5] = a + b; temp[8 * i + 7] = a - b;
}
{
    int a, b;
    a = temp[8 * i + 0]; b = temp[8 * i + 4];
    temp[8 * i + 0] = a + b; temp[8 * i + 4] = a - b;
}
{
    int a, b;
    a = temp[8 * i + 1]; b = temp[8 * i + 5];
    temp[8 * i + 1] = a + b; temp[8 * i + 5] = a - b;
}
{
    int a, b;
    a = temp[8 * i + 2]; b = temp[8 * i + 6];
    temp[8 * i + 2] = a + b; temp[8 * i + 6] = a - b;
}
{
    int a, b;
    a = temp[8 * i + 3]; b = temp[8 * i + 7];
    temp[8 * i + 3] = a + b; temp[8 * i + 7] = a - b;
}

i = 6;
temp[8 * i + 0] = (src[stride * i + 0]) + (src[stride * i + 1]);
temp[8 * i + 1] = (src[stride * i + 0]) - (src[stride * i + 1]);
temp[8 * i + 2] = (src[stride * i + 2]) + (src[stride * i + 3]);
temp[8 * i + 3] = (src[stride * i + 2]) - (src[stride * i + 3]);
temp[8 * i + 4] = (src[stride * i + 4]) + (src[stride * i + 5]);
temp[8 * i + 5] = (src[stride * i + 4]) - (src[stride * i + 5]);
temp[8 * i + 6] = (src[stride * i + 6]) + (src[stride * i + 7]);
temp[8 * i + 7] = (src[stride * i + 6]) - (src[stride * i + 7]);

{
    int a, b;
    a = temp[8 * i + 0]; b = temp[8 * i + 2];
    temp[8 * i + 0] = a + b; temp[8 * i + 2] = a - b;
}
{
    int a, b;
    a = temp[8 * i + 1]; b = temp[8 * i + 3];
    temp[8 * i + 1] = a + b; temp[8 * i + 3] = a - b;
}
{
    int a, b;
    a = temp[8 * i + 4]; b = temp[8 * i + 6];
    temp[8 * i + 4] = a + b; temp[8 * i + 6] = a - b;
}
{
    int a, b;
    a = temp[8 * i + 5]; b = temp[8 * i + 7];
    temp[8 * i + 5] = a + b; temp[8 * i + 7] = a - b;
}
{
    int a, b;
    a = temp[8 * i + 0]; b = temp[8 * i + 4];
    temp[8 * i + 0] = a + b; temp[8 * i + 4] = a - b;
}
{
    int a, b;
    a = temp[8 * i + 1]; b = temp[8 * i + 5];
    temp[8 * i + 1] = a + b; temp[8 * i + 5] = a - b;
}
{
    int a, b;
    a = temp[8 * i + 2]; b = temp[8 * i + 6];
    temp[8 * i + 2] = a + b; temp[8 * i + 6] = a - b;
}
{
    int a, b;
    a = temp[8 * i + 3]; b = temp[8 * i + 7];
    temp[8 * i + 3] = a + b; temp[8 * i + 7] = a - b;
}

i = 7;
temp[8 * i + 0] = (src[stride * i + 0]) + (src[stride * i + 1]);
temp[8 * i + 1] = (src[stride * i + 0]) - (src[stride * i + 1]);
temp[8 * i + 2] = (src[stride * i + 2]) + (src[stride * i + 3]);
temp[8 * i + 3] = (src[stride * i + 2]) - (src[stride * i + 3]);
temp[8 * i + 4] = (src[stride * i + 4]) + (src[stride * i + 5]);
temp[8 * i + 5] = (src[stride * i + 4]) - (src[stride * i + 5]);
temp[8 * i + 6] = (src[stride * i + 6]) + (src[stride * i + 7]);
temp[8 * i + 7] = (src[stride * i + 6]) - (src[stride * i + 7]);

{
    int a, b;
    a = temp[8 * i + 0]; b = temp[8 * i + 2];
    temp[8 * i + 0] = a + b; temp[8 * i + 2] = a - b;
}
{
    int a, b;
    a = temp[8 * i + 1]; b = temp[8 * i + 3];
    temp[8 * i + 1] = a + b; temp[8 * i + 3] = a - b;
}
{
    int a, b;
    a = temp[8 * i + 4]; b = temp[8 * i + 6];
    temp[8 * i + 4] = a + b; temp[8 * i + 6] = a - b;
}
{
    int a, b;
    a = temp[8 * i + 5]; b = temp[8 * i + 7];
    temp[8 * i + 5] = a + b; temp[8 * i + 7] = a - b;
}
{
    int a, b;
    a = temp[8 * i + 0]; b = temp[8 * i + 4];
    temp[8 * i + 0] = a + b; temp[8 * i + 4] = a - b;
}
{
    int a, b;
    a = temp[8 * i + 1]; b = temp[8 * i + 5];
    temp[8 * i + 1] = a + b; temp[8 * i + 5] = a - b;
}
{
    int a, b;
    a = temp[8 * i + 2]; b = temp[8 * i + 6];
    temp[8 * i + 2] = a + b; temp[8 * i + 6] = a - b;
}
{
    int a, b;
    a = temp[8 * i + 3]; b = temp[8 * i + 7];
    temp[8 * i + 3] = a + b; temp[8 * i + 7] = a - b;
}
}
