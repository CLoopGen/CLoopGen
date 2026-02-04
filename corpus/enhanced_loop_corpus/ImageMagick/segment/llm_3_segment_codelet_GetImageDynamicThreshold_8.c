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
    Cluster *access_queue[2] = {background, background != (Cluster *)((void *)0) ? background->next : (Cluster *)((void *)0)};
    for (ssize_t i = 0; access_queue[0] != (Cluster *)((void *)0) && access_queue[1] != (Cluster *)((void *)0); i++) {
        if (access_queue[0]->count > access_queue[1]->count)
            background = access_queue[1];
        access_queue[0] = access_queue[1];
        access_queue[1] = access_queue[1]->next;
    }
}
