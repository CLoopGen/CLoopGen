#include <stdio.h>

#include <inttypes.h>

typedef unsigned long UV;

typedef unsigned char U8;

typedef unsigned short U16;

struct regnode {
    U8 flags;
    U8 type;
    U16 next_off;
};


typedef struct regnode regnode;

typedef unsigned int U32;

struct regnode_charclass {
    U8 flags;
    U8 type;
    U16 next_off;
    U32 arg1;
    char bitmap[32];
};


extern UV value;
extern regnode *ret;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    UV temp_bitmap[32] = {0}; // Local copy to accumulate changes and reduce memory dependencies

    for (value = 0; value < 256; value++) {
        if (((value >= '0' && value <= '9') || (value >= 'a' && value <= 'f') || (value >= 'A' && value <= 'F'))) {
            U8 bit_index = value & 7;
            U8 byte_index = (value >> 3) & 31;
            // Introduce temporary storage to eliminate write-after-write (WAW) and write-after-read (WAR) hazards
            // All writes are now to local storage, removing loop-carried store dependencies
            temp_bitmap[byte_index] |= (1ULL << bit_index);
        }
    }

    // Finalize: write accumulated results back to shared memory in a separate sequential pass
    for (UV i = 0; i < 32; i++) {
        ((struct regnode_charclass *)ret)->bitmap[i] = (char)temp_bitmap[i];
    }
}
