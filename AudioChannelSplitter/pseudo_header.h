#pragma once
#include <cstdint>
typedef struct  PSEUDO_HEADER
{
    uint32_t        ChunkSize;      // RIFF Chunk Size
    uint16_t        NumOfChan;      // Number of channels 1=Mono 2=Sterio
    uint16_t        BitsPerSample;  // Number of bits per sample
    uint32_t        Subchunk2Size;  // Sampled data length
    uint16_t        BytesPerSample;
    uint32_t        NumSamples;
} pse_hdr;