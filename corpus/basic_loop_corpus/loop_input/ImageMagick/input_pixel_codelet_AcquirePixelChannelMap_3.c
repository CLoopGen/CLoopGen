#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef enum {
    UndefinedPixelChannel = 0,
    RedPixelChannel = 0,
    CyanPixelChannel = 0,
    GrayPixelChannel = 0,
    LPixelChannel = 0,
    LabelPixelChannel = 0,
    YPixelChannel = 0,
    aPixelChannel = 1,
    GreenPixelChannel = 1,
    MagentaPixelChannel = 1,
    CbPixelChannel = 1,
    bPixelChannel = 2,
    BluePixelChannel = 2,
    YellowPixelChannel = 2,
    CrPixelChannel = 2,
    BlackPixelChannel = 3,
    AlphaPixelChannel = 4,
    IndexPixelChannel = 5,
    ReadMaskPixelChannel = 6,
    WriteMaskPixelChannel = 7,
    MetaPixelChannel = 8,
    CompositeMaskPixelChannel = 9,
    MetaPixelChannels = 10,
    IntensityPixelChannel = 64,
    CompositePixelChannel = 64,
    SyncPixelChannel = 64 + 1
} PixelChannel;

typedef enum {
    UndefinedPixelTrait = 0,
    CopyPixelTrait = 1,
    UpdatePixelTrait = 2,
    BlendPixelTrait = 4
} PixelTrait;

typedef struct _PixelChannelMap {
    PixelChannel channel;
    PixelTrait traits;
    ssize_t offset;
} PixelChannelMap;

PixelChannelMap *channel_map;
ssize_t i;

void init_vars() {
    const size_t data_size = 256 * 1024 * 1024; // 256 MB
    const size_t num_elements = data_size / sizeof(PixelChannelMap);
    
    // Ensure we have at least 65 elements for the loop to access indices 0..64
    size_t alloc_elements = (num_elements > 65) ? num_elements : 65;
    
    channel_map = (PixelChannelMap*)calloc(alloc_elements, sizeof(PixelChannelMap));
    if (!channel_map) {
        // Fallback: ensure minimum required size
        channel_map = (PixelChannelMap*)calloc(65, sizeof(PixelChannelMap));
    }
    
    // Initialize all elements
    for (size_t idx = 0; idx < 65; idx++) {
        channel_map[idx].channel = (PixelChannel)idx;
        channel_map[idx].traits = UndefinedPixelTrait;
        channel_map[idx].offset = 0;
    }
}