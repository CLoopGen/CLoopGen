#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int qlevels[5];
extern int i;
extern int largest;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < 5; i++) {
    if (qlevels[i] < qlevels[largest])
        largest = i;
}

}
