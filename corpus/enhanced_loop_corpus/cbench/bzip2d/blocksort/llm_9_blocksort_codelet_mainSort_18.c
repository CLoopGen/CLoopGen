#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef unsigned char UChar;

typedef int Int32;

typedef unsigned short UInt16;

extern UInt32 *ptr;
extern UChar *block;
extern UInt32 *ftab;
extern Int32 i;
extern Int32 j;
extern UInt16 s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
UInt32 temp_s[4];
Int32 temp_j[4];
Int32 indices[4] = {i, i - 1, i - 2, i - 3};

for (; i >= 3; i -= 4) {
    temp_s[0] = (s >> 8) | (block[indices[0]] << 8);
    temp_j[0] = ftab[temp_s[0]] - 1;
    ftab[temp_s[0]] = temp_j[0];
    ptr[temp_j[0]] = indices[0];

    temp_s[1] = (temp_s[0] >> 8) | (block[indices[1]] << 8);
    temp_j[1] = ftab[temp_s[1]] - 1;
    ftab[temp_s[1]] = temp_j[1];
    ptr[temp_j[1]] = indices[1];

    temp_s[2] = (temp_s[1] >> 8) | (block[indices[2]] << 8);
    temp_j[2] = ftab[temp_s[2]] - 1;
    ftab[temp_s[2]] = temp_j[2];
    ptr[temp_j[2]] = indices[2];

    s = (temp_s[2] >> 8) | (block[indices[3]] << 8);
    j = ftab[s] - 1;
    ftab[s] = j;
    ptr[j] = indices[3];

    indices[0] -= 4; indices[1] -= 4;
    indices[2] -= 4; indices[3] -= 4;
}
}
