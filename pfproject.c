#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <unistd.h>
int main() {
	// Declare and initialize variables
	char predefined[50] = {"Alexander! please answer the following question"}; // Predefined string
	char answer[50]; // Array to store the answer
	char currentChar; // Variable to store the current character input
	int currentIndex = 0; // Index for tracking the current character position in the predefined string
	int answerIndex = 0; // Index for tracking the current character position in the answer
	int boss = 0; // Flag to check if the "boss" mode is activated
	
	// Prompt the user to input the predefined string
	printf("Enter: \"%s\"\n", predefined);

	// Loop to handle user input until Enter (ASCII 13) is pressed
	while ((currentChar = getch()) != 13) {
		if (currentChar == 8) {
			// Backspace key (ASCII 8) handling
			putch('\b');
			putch(' ');
			putch('\b');
			currentIndex--;
			continue;
		}  
		else if (currentChar == 47) {
			// Slash key (ASCII 47) activates "boss" mode
			boss = 1;
			printf("%c", predefined[currentIndex++]);

			// Loop to capture the answer 
			while (1) {
				currentChar = getch();
				if (currentChar == 8) {	
					// Backspace key (ASCII 8) handling in "boss" mode		
					putch('\b');
					putch(' ');
					putch('\b');
					currentIndex--;
					continue;
				} 
				if (currentChar == 47) {
					// Slash key (ASCII 47) ends "boss" mode
					printf("%c", predefined[currentIndex]);
					currentChar = getch();
					break;
				} 
				else {
					// Capture user's answer and display predefined string
					answer[answerIndex++] = currentChar;
					printf("%c", predefined[currentIndex++]);
				}
			}
		}
		printf("%c", currentChar);
		currentIndex++;
	}

	// Check if "boss" mode is activated
	if (boss == 1) {
		// If "boss" mode is activated, prompt the user for their question
		printf("\n\nEnter your question here:\n");
		scanf("%s");
		printf("\nThinking...");
		sleep(3);  // Pause execution for 3 seconds 
		printf("\n\nAnswer: %s", answer);
	} 
	else {
		// If "boss" mode is not activated, display a message
		printf("\n\nNo, I will answer my boss only.");
		printf("\n\n\t  ENDED");
	}
	
	return 0; // end the program
}
