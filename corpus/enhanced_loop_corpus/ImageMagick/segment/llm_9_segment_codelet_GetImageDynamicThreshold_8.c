#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct _ExtentPacket {
    double center;
    ssize_t index;
    ssize_t left;
    ssize_t right;
} ExtentPacket;

typedef struct _Cluster {
    struct _Cluster *next;
    ExtentPacket red;
    ExtentPacket green;
    ExtentPacket blue;
    ssize_t count;
    ssize_t id;
} Cluster;

extern Cluster *background;
extern Cluster *cluster;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational complexity with unrolled condition checks and fixed small trip bound
    Cluster *current = background;
    ssize_t iter = 0;
    const ssize_t max_iters = 4;  // Limit iterations regardless of list length

    for (; iter < max_iters && current != (Cluster *)((void *)0) && current->next != (Cluster *)((void *)0); 
         iter++, current = current->next) {
        // Simplified comparison without side effects on background unless strictly dominant
        if (current->count > current->next->count)
            background = current->next;
    }

    // Final assignment to maintain original semantics influence
    cluster = background;
}
