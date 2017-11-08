#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <regex.h>
int main (int argc, char *argv[]) {
	if (argc < 2) {
		// Asign memory for input string, token, and create a some pointers to itterate through everything
		char str1[256], *saveptr1, token=" \t\n";
		// We are going to parse input stream
		int numberOfWords = 0;
		printf("Please enter a string to count the words of:\n");
		fgets(str1, 256, stdin);
		printf("\n\nThe number of characters in the stream was %d\n", (int) strlen(str1));
		saveptr1 = strtok(str1, token);
		while (saveptr1 != NULL) {
			numberOfWords++;
			saveptr1 = strtok(NULL, token);
		}
		printf("Number of words in the string was: %d\n", numberOfWords);
	} else {
		printf("\nLine Count\tWord Count\tCharacter Count\tName of File\n");
		// We are going through files
		for (int i = 1; i < (argc); i++){
			// Create int storage for word count, newline count, and words
			int numberOfWords = 0, numberOfLines = 0, numberOfCharacters = 0;
			char buffer[256];
			// Count number of new lines
			FILE *newLineFP = fopen(argv[i], "r+");
			while (fscanf(newLineFP, "%c", buffer) != EOF) {
				numberOfCharacters++;
				if (buffer[0] == '\n')
					numberOfLines++;
			}
			// Close initla handle to file
			fclose(newLineFP);
			// Open file again to parse word count
			FILE *fp = fopen(argv[i], "r+");
			// Loop through and count words
			while(fscanf(fp, "%s" ,buffer) != EOF) {
				numberOfWords++;
			}
			// Close file handle
			fclose(fp);
			// Print the results per file
			printf("\t%d\t%d\t\t%d\t\t%s\n", numberOfLines, numberOfWords, numberOfCharacters, argv[i]);
		}
	}
	return 0;
}
