#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t arr[2] = {0, 1};
    for (i = 0; i < 1027; i++) {
        uint64_t next = arr[0] + arr[1];
        arr[0] = arr[1];       // WAW and WAR dependency: arr[0] is updated after use
        arr[1] = next;         // Loop-carried dependency: each iteration depends on prior state (Fibonacci-like)
    }
}
