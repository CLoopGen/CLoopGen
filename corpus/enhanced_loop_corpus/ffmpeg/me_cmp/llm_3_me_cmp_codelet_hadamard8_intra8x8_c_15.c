#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int temp[64];
extern int sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int stride = 8;
for (i = 0; i < 8; i++) {
    int base_idx[8];
    for (int j = 0; j < 8; j++) {
        base_idx[j] = j * stride + i;
    }
    {
        int a, b;
        a = temp[base_idx[0]];
        b = temp[base_idx[1]];
        temp[base_idx[0]] = a + b;
        temp[base_idx[1]] = a - b;
    }
    ;
    {
        int a, b;
        a = temp[base_idx[2]];
        b = temp[base_idx[3]];
        temp[base_idx[2]] = a + b;
        temp[base_idx[3]] = a - b;
    }
    ;
    {
        int a, b;
        a = temp[base_idx[4]];
        b = temp[base_idx[5]];
        temp[base_idx[4]] = a + b;
        temp[base_idx[5]] = a - b;
    }
    ;
    {
        int a, b;
        a = temp[base_idx[6]];
        b = temp[base_idx[7]];
        temp[base_idx[6]] = a + b;
        temp[base_idx[7]] = a - b;
    }
    ;
    {
        int a, b;
        a = temp[base_idx[0]];
        b = temp[base_idx[2]];
        temp[base_idx[0]] = a + b;
        temp[base_idx[2]] = a - b;
    }
    ;
    {
        int a, b;
        a = temp[base_idx[1]];
        b = temp[base_idx[3]];
        temp[base_idx[1]] = a + b;
        temp[base_idx[3]] = a - b;
    }
    ;
    {
        int a, b;
        a = temp[base_idx[4]];
        b = temp[base_idx[6]];
        temp[base_idx[4]] = a + b;
        temp[base_idx[6]] = a - b;
    }
    ;
    {
        int a, b;
        a = temp[base_idx[5]];
        b = temp[base_idx[7]];
        temp[base_idx[5]] = a + b;
        temp[base_idx[7]] = a - b;
    }
    ;
    sum += ((((temp[base_idx[0]]) + (temp[base_idx[4]])) >= 0 ? ((temp[base_idx[0]]) + (temp[base_idx[4]])) : (-((temp[base_idx[0]]) + (temp[base_idx[4]])))) + (((temp[base_idx[0]]) - (temp[base_idx[4]])) >= 0 ? ((temp[base_idx[0]]) - (temp[base_idx[4]])) : (-((temp[base_idx[0]]) - (temp[base_idx[4]]))))) + ((((temp[base_idx[1]]) + (temp[base_idx[5]])) >= 0 ? ((temp[base_idx[1]]) + (temp[base_idx[5]])) : (-((temp[base_idx[1]]) + (temp[base_idx[5]])))) + (((temp[base_idx[1]]) - (temp[base_idx[5]])) >= 0 ? ((temp[base_idx[1]]) - (temp[base_idx[5]])) : (-((temp[base_idx[1]]) - (temp[base_idx[5]]))))) + ((((temp[base_idx[2]]) + (temp[base_idx[6]])) >= 0 ? ((temp[base_idx[2]]) + (temp[base_idx[6]])) : (-((temp[base_idx[2]]) + (temp[base_idx[6]])))) + (((temp[base_idx[2]]) - (temp[base_idx[6]])) >= 0 ? ((temp[base_idx[2]]) - (temp[base_idx[6]])) : (-((temp[base_idx[2]]) - (temp[base_idx[6]]))))) + ((((temp[base_idx[3]]) + (temp[base_idx[7]])) >= 0 ? ((temp[base_idx[3]]) + (temp[base_idx[7]])) : (-((temp[base_idx[3]]) + (temp[base_idx[7]])))) + (((temp[base_idx[3]]) - (temp[base_idx[7]])) >= 0 ? ((temp[base_idx[3]]) - (temp[base_idx[7]])) : (-((temp[base_idx[3]]) - (temp[base_idx[7]])))));
}
}
