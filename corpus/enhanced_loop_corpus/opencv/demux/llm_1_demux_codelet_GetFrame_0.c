#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    size_t start;
    size_t end;
    size_t riff_end;
    size_t buf_size;
    const int *buf;
} MemBuffer;

typedef struct {
    size_t offset;
    size_t size;
} ChunkData;

typedef struct Frame {
    int x_offset;
    int y_offset;
    int width;
    int height;
    int has_alpha;
    int duration;
    int dispose_method;
    int blend_method;
    int frame_num;
    int complete;
    ChunkData img_components[2];
    struct Frame *next;
} Frame;

typedef struct Chunk {
    ChunkData data;
    struct Chunk *next;
} Chunk;

struct WebPDemuxer {
    MemBuffer mem;
    int state;
    int is_ext_format;
    int feature_flags;
    int canvas_width;
    int canvas_height;
    int loop_count;
    int bgcolor;
    int num_frames;
    Frame *frames;
    Frame **frames_tail;
    Chunk *chunks;
    Chunk **chunks_tail;
};


extern  struct WebPDemuxer * dmux;
extern int frame_num;
extern  Frame *f;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Decreased effective nesting depth by flattening potential multi-loop logic
    // Here, we remove any unnecessary blocks and keep the loop as a single flat traversal
    for (f = dmux->frames; f != NULL && f->frame_num != frame_num; f = f->next);
}
