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


// Types, where we can just add a new one
// TODO: Can this be done elsewhere?
#define FILETYPES \
	".png", \
	".jpeg", \
	".jpg", \
	".bmp", \
	".webp", \
	".ppm"

bool filename_is_extension (const char *filename);

ImageType detect_filetype(const char *filepath);

char* return_filetype(ImageType type);


#endif
