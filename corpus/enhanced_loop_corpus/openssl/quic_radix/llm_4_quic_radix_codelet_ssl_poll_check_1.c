#include <stdio.h>

#include <inttypes.h>

typedef struct ssl_st SSL;

union {
    int fd;
    void *custom;
    uintptr_t custom_ui;
    SSL *ssl;
};


typedef struct bio_poll_descriptor_st {
    uint32_t type;
    union {
        int fd;
        void *custom;
        uintptr_t custom_ui;
        SSL *ssl;
    } value;
} BIO_POLL_DESCRIPTOR;

typedef struct ssl_poll_item_st {
    BIO_POLL_DESCRIPTOR desc;
    uint64_t events;
    uint64_t revents;
} SSL_POLL_ITEM;

extern SSL_POLL_ITEM items[6];
extern SSL_POLL_ITEM expected_items[6];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; ++i) {
        if ((i + 1) % 2 == 0) {
            items[i + 1].events |= (1U << 7);
            expected_items[i + 1].revents |= (1U << 7);
        }
    }
}
