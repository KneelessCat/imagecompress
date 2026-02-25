// Alright.
//
// Next task(s) for small start! :D
//
// 1. Create a small text window to introduce it, minimal ascii art, with options for loading an image, and exiting
// 2. Print the rgb values
// 3. Start with PPM. Really 'easy' starting point. Then worry about other formats
// 4. We'll want to work with other formats later, will want to check the file format when taking it in (so allow program to accept .png, /jpg etc. and just display a small 'not implemented yet!' message

#include <stdio.h>
#include <string.h>
#include "main.h"

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
}

int main() {
	boxMessage();
	//return 0;


		
	// Loops, just keeps program open until typing 1 to exit
	printf("\nType 1, and then ENTER to exit. ");
	int exit = 0;

	while (true) {
		scanf("%d", &exit);

		if (exit == 1) {
			return 0;
		}
	}

}
