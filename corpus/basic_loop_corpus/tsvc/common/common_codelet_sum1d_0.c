#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

extern real_t arr[32000];
extern real_t ret;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (int i = 0; i < 32000; i++)
    ret += arr[i];

}
