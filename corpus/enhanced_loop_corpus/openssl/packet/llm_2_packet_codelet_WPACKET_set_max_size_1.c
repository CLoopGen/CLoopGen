#include <stdio.h>

#include <inttypes.h>

struct buf_mem_st {
    size_t length;
    char *data;
    size_t max;
    unsigned long flags;
};


typedef struct buf_mem_st BUF_MEM;

typedef struct wpacket_sub WPACKET_SUB;

struct wpacket_sub {
    WPACKET_SUB *parent;
    size_t packet_len;
    size_t lenbytes;
    size_t pwritten;
    unsigned int flags;
};


struct wpacket_st {
    BUF_MEM *buf;
    unsigned char *staticbuf;
    size_t curr;
    size_t written;
    size_t maxsize;
    WPACKET_SUB *subs;
    unsigned int endfirst : 1;
};


typedef struct wpacket_st WPACKET;

extern WPACKET *pkt;
extern WPACKET_SUB *sub;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern using pointer arithmetic with a fixed stride (simulated via intermediate steps)
    WPACKET_SUB *current = pkt->subs;
    for (; current != ((void *)0) && current->parent != ((void *)0); current = (WPACKET_SUB*)((char*)current + sizeof(WPACKET_SUB)))
        if (current == current->parent)
            break;
}
