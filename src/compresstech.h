#ifndef COMPRESSTECH_H
#define COMPRESSTECH_H


typedef enum {
    UNKNOWN,
    RLE,
    HUFFMAN,
    LZ77,
    LZW
} CompressionType;

CompressionType compression();


#endif