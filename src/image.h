#ifndef IMAGE_H
#define IMAGE_H

// An enum to store each image type the program supports
// If we encounter an unknown image type, we throw an error
typedef enum ImageTypeName {
    UNKNOWN,    // Unknown
    PPM,    // .ppm
    BMP,    // .bmp
    PNG,    // .png
    JPG,    //  .jpg or .jpeg
    WEBP    // .webp
} ImageType;


ImageType detect_filetype(const char *filepath);


#endif