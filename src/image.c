#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "image.h"

const char *FILEEXTS[] = { FILETYPES };
const size_t EXTCOUNT = sizeof(FILEEXTS) / sizeof(FILEEXTS[0]);


// This function is used to make sure the user's file input is not just the file extension (e.g. a file can't just be called ".png"
//TODO: Technically, unknown file types where the filename is just the unknown file type (e.g. ".jpegs") pass this check, but other conditions block from proceeding, maybe we change this so it catches these cases anyways. E.g. maybe we just make a functon to check that the filename is not beginning with a non a-zA-Z character?
bool filename_is_extension(const char *filename) {
	for (size_t i = 0; i < EXTCOUNT; i++) {
		if (strcmp(filename, FILEEXTS[i]) == 0) {
			return true;
		}
	}

	return false;
}

// This function takes a file path, and then detects the file type of the target file
//
// inputs: const char *filepath
// returns: ImageType
ImageType detect_filetype(const char *filepath) {
    printf("RAW INPUT: '%s'\n", filepath);

    // If the string doesn't contain a period, just print error and return for now
    // TODO: Fix error
    if (!strchr(filepath, '.')) {
        printf("Invalid input! No file.\n");
        return UNKNOWN;
    }

    // Copy the file path as processing alters the contents of the string
    char *copypath = malloc(strlen(filepath) + 1); // + 1 to account for '\0' null terminator
    strcpy(copypath, filepath);

    // Get the first token
    char *token = strtok(copypath, ".");
    char *lastToken = token;

    // We first need to make sure the argument is not just .png, .ppm or etc. It can't just be the file extension
    //TODO: Fix error
    if(filename_is_extension(filepath)) {
	printf("No extension! Invalid input.\n");
	return UNKNOWN;
    }

    //TODO: We need to ensure file has an extension. Technically other checks do it but inputs like "png" "jpeg" as a filename get through
    printf("NEED TO IMPLEMENT IMAGE.C line 54.\n");

    // Move Through other tokens
    while (token != NULL) {
        lastToken = token;
        token = strtok(NULL, ".");
    }

    // If we are left with NULL or an empty string
    // TODO: Fix error
    if (lastToken == NULL || lastToken[0] == '\0') {
        printf("No file detected!\n");
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


    /*
     typedef enum ImageTypeName {
    UNKNOWN,    // Unknown
    PPM,    // .ppm
    BMP,    // .bmp
    PNG,    // .png
    JPG,    //  .jpg or .jpeg
    WEBP    // .webp
    } ImageType;
    
    */

    if (strcmp(extn, ".ppm") == 0) {
        type = PPM;
    }
    
    else if (strcmp(extn, ".bmp") == 0) {
        type = BMP;
    }
    
    else if (strcmp(extn, ".png") == 0) {
        type = PNG;
    }

    else if (strcmp(extn, ".jpg") == 0 || strcmp(extn, ".jpeg") == 0) {
        type = JPG;
    }

    else if (strcmp(extn, ".webp") == 0) {
        type = WEBP;
    }

    free(extn);

    return type;

}


// Here, we return the file type (mostly for debugging, this just reverses the process of extracting the file type and converting to ImageType
char* return_filetype(ImageType type) {
	switch(type) {
		case 0: return "Unknown";
		case 1: return "ppm";
		case 2: return "bmp";
		case 3: return "png";
		case 4: return "jpg/jpeg";
		case 5: return "webp";
	}

	// We should never get here
	// TODO: Make error
	return "Error. Not a file type.";
}
