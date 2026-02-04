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

static struct WebPDemuxer dmux_instance;
struct WebPDemuxer *dmux = &dmux_instance;
int frame_num;
Frame *f;

static int *create_aligned_int_buffer(size_t count) {
    int *buf = aligned_alloc(64, sizeof(int) * count);
    for (size_t i = 0; i < count; ++i) {
        buf[i] = (int)i;
    }
    return buf;
}

static void init_chunks() {
    Chunk **tail = &dmux->chunks;
    dmux->chunks = NULL;
    const size_t chunk_count = 1000;
    for (size_t i = 0; i < chunk_count; ++i) {
        Chunk *c = malloc(sizeof(Chunk));
        c->data.offset = i * 1024;
        c->data.size = 1024;
        c->next = NULL;
        *tail = c;
        tail = &c->next;
    }
    dmux->chunks_tail = tail;
}

void init_vars() {
    const size_t buffer_size = 32 * 1024 * 1024 / sizeof(int);
    int *buffer = create_aligned_int_buffer(buffer_size);

    dmux->mem.buf = buffer;
    dmux->mem.buf_size = buffer_size;
    dmux->mem.start = 0;
    dmux->mem.end = buffer_size / 2;
    dmux->mem.riff_end = buffer_size;

    dmux->state = 1;
    dmux->is_ext_format = 1;
    dmux->feature_flags = 0x1F;
    dmux->canvas_width = 800;
    dmux->canvas_height = 600;
    dmux->loop_count = 0;
    dmux->bgcolor = 0xFFFFFFFF;
    dmux->num_frames = 50000;

    Frame **tail = &dmux->frames;
    dmux->frames = NULL;
    for (int i = 0; i < 50000; ++i) {
        Frame *frame = malloc(sizeof(Frame));
        frame->x_offset = i % 100;
        frame->y_offset = i % 100;
        frame->width = 100;
        frame->height = 100;
        frame->has_alpha = 1;
        frame->duration = 100;
        frame->dispose_method = 1;
        frame->blend_method = 1;
        frame->frame_num = i;
        frame->complete = 1;
        frame->img_components[0].offset = i * 2 * 1024;
        frame->img_components[0].size = 1024;
        frame->img_components[1].offset = i * 2 * 1024 + 1024;
        frame->img_components[1].size = 1024;
        frame->next = NULL;
        *tail = frame;
        tail = &frame->next;
    }
    dmux->frames_tail = tail;

    init_chunks();

    frame_num = 49999;
}