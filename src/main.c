/*
// Lines for the intro box
const char *textLines[] = {
	"Hello, welcome to my image compressor!",
	"1. Load an image (PPM Supported only at the moment).",
	"test",
	"and some more lines!",
	"and another"
};

// Each line is a pointer (8 bytes), so divide total number of bytes by 8
const int textLineCount = sizeof(textLines) / sizeof(textLines[0]);

// Function for the top and bottom lines
void boxLine() {
	printf("+");

	for (int i = 0; i < BOX_WIDTH; i++) {
		printf("-");
	}

	printf("+\n");
}

void boxTextLine(const char* text) {
	int leng = strlen(text);

	// We determine the total amount of white space
	// Subtract 2 for the two '|' on either side
	// Remove the length of the text, as it's taking up space that would otherwise be used for padding
	int padding = BOX_WIDTH - leng;

	int left = padding / 2;
	int right  = padding / 2;

	printf("|");

	for (int k = 0; k < left; k++) {
		printf(" ");
	}

	printf("%s", text);

	for (int k = 0; k < right; k++) {
		printf(" ");
	}

	printf("|\n");
}


void boxMessage() {
	boxLine();
	
	// Loops through each line
	for (int k = 0; k < textLineCount; k++) {
		// Prints the text along with box border
		boxTextLine(textLines[k]);
	}

	boxLine();

	printf("\n");
}*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>


#include "main.h"
#include "image.h"

const char *VALIDCARGS[] = {"compress","compression","c"};
const char *VALIDDARGS[] = {"decompress", "decompression", "d"};


// This function takes the real argument passed in for compression/decompression, and checks if it is valid
bool isValidArg(char *realarg) {
	// C and D args should be same length, so we just calculate size once
	// 24 (3 pointers) divided by 8 (size of one pointer) = 3
	int leng = (sizeof(VALIDCARGS) / sizeof(VALIDCARGS[0]));

	// Convert the argument to lowercase
	for (char *c = realarg; *c != '\0'; c++) {
		*c = tolower(*c);
	}

	// Check if the argument matches any of the valid ones (defined in CARGS and DARGS)
	for (int k = 0; k < leng; k++) {

		// If it matches either a compression or decompression argument, we exit the function with true (is valid)
		if (!strcmp(realarg, VALIDCARGS[k]) || !strcmp(realarg, VALIDDARGS[k])) {
			return true;
		}
	}

	return false;
}


/*int main() {
	boxMessage();
	//return 0

	// Loops, just keeps program open until typing 1 to exit
	printf("\nNothing here... Type 1, and then ENTER to exit. ");
	int exit = 0;

	while (true) {
		scanf("%d", &exit);

		if (exit == 1) {
			return 0;
		}
	}	
	return 0;

}*/

int main(int argc, char *argv[]) {
	// TODO: error messages later

	// We must have three additional arguments
	//		mode (compress - or c, decompress - or d)
	//		input (image to input)
	//		output (resultant image) - IGNORE FOR NOW

	// First argument is executable name
	// Only two additional arguments for now
	if (argc != 3) {
		printf("Nothing...");
		return -1;
	}

	else {

		// If an invalid argument, we exit the program 
		if (!(isValidArg(argv[1]))) {
			return -1;
		}

		// Get the file type of second user-defined arg for now
		detect_filetype(argv[2]);
	}

}


/*
main.c

Literally just takes the arguments passed into the program when its run

load image function

image.c/image.h

image.h can have the function signatures and an enum for each file type
implemented (e.g. PPM, BMP).

image.c will detect file type by parsing the extension. And load image?

*/