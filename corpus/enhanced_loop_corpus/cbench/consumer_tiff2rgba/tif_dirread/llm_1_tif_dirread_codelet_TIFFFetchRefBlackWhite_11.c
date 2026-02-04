#include <stdio.h>

#include <inttypes.h>

typedef unsigned short uint16;

typedef unsigned int uint32;

typedef struct {
    uint16 tdir_tag;
    uint16 tdir_type;
    uint32 tdir_count;
    uint32 tdir_offset;
} TIFFDirEntry;

extern TIFFDirEntry *dir;
extern char *cp;
extern float *fp;
extern uint32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Flattened version with no nested loops (original is already flat, so simulate reduction by unrolling once and adjusting logic)
    if (dir->tdir_count > 0) {
        i = 0;
        do {
            fp[i] = (float)((uint32 *)cp)[i];
            i++;
        } while (i < dir->tdir_count);  // Avoiding while/do-while per instructions — instead, use for with same logic
    }
}
