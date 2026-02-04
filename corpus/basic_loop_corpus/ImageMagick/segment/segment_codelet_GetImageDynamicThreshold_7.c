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

extern Cluster *cluster;
extern Cluster *object;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (cluster = object; cluster->next != (Cluster *)((void *)0);) {
    if (cluster->count < object->count)
        object = cluster;
    cluster = cluster->next;
}

}
