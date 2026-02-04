#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

extern real_t arr[32000];
extern real_t ret;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 100; j++)
        for (int i = 0; i < 320; i++)
            ret += arr[j * 320 + i];
}
