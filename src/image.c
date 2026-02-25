#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "image.h"

// This function takes a file path, and then detects the file type of the target file
//
// inputs: const char *filepath
// returns: ImageType
ImageType detect_filetype(const char *filepath) {
    printf("RAW INPUT: '%s'\n", filepath);

    // If the string doesn't contain a period, just print error and return for now
    if (!strchr(filepath, '.')) {
        printf("Invalid input!");
        return UNKNOWN;
    }

    // Copy the file path as processing alters the contents of the string
    char *copypath = malloc(strlen(filepath) + 1); // + 1 to account for '\0' null terminator
    strcpy(copypath, filepath);

    // Get the first token
    char *token = strtok(copypath, ".");
    char *lastToken = token;

    // Move Through other tokens
    while (token != NULL) {
        lastToken = token;
        token = strtok(NULL, ".");
        printf("Iteration\n");
    }

    // If we are left with NULL or an empty string
    if (lastToken == NULL || lastToken[0] == '\0') {
        printf("Bad!\n");
        free(copypath);
        return UNKNOWN;
    }

    // Stores file extension
    char *extn = malloc(strlen(lastToken) + 2); // + 2 to account for the . and for the '\0' null terminator

    // Define the first byte of allocated memory with the "."
    extn[0] = '.';
    
    // Start copying on the second byte of allocated memory
    strcpy(extn + 1, lastToken);

    free(copypath);

    // Map the file extension to the ImageType enum
    ImageType type = UNKNOWN;

    if (strcmp(extn, ".ppm") == 0) {
        printf("PPM");
    }
    
    else if (strcmp(extn, ".bmp") == 0) {
        printf("BMP");
    }
    
    else if (strcmp(extn, ".png") == 0) {
        printf("PNG");
    }

    else if (strcmp(extn, ".jpg") == 0 || strcmp(extn, ".jpeg") == 0) {
        printf("JPG/JPEG");
    }

    else if (strcmp(extn, ".webp") == 0) {
        printf("JPG");
    }
    
    else {
        printf("Unknown file type %s", extn);
    }

    free(extn);

    return 0;

}