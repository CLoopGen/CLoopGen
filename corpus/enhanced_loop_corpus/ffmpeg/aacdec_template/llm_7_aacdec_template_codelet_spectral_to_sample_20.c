#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int type;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int arr[4] = {1, 2, 3, 4};
    for (type = 3; type >= 0; type--) {
        arr[type] = arr[(type + 1) % 4] + 1;
    }
}
