#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <unistd.h>
int main() {
	char predefined[50] = {"Alexander! please answer the following question"}; 
	char answer[50]; 
	char currentChar; 
	int currentIndex = 0; 
	int answerIndex = 0; 
	int boss = 0; 
	
	printf("Enter: \"%s\"\n", predefined);

	while ((currentChar = getch()) != 13) {
		if (currentChar == 8) {
			putch('\b');
			putch(' ');
			putch('\b');
			currentIndex--;
			continue;
		}  
		else if (currentChar == 47) {
			boss = 1;
			printf("%c", predefined[currentIndex++]);

			while (1) {
				currentChar = getch();
				if (currentChar == 8) {			
					putch('\b');
					putch(' ');
					putch('\b');
					currentIndex--;
					continue;
				} 
				if (currentChar == 47) {
					printf("%c", predefined[currentIndex]);
					currentChar = getch();
					break;
				} 
				else {
					answer[answerIndex++] = currentChar;
					printf("%c", predefined[currentIndex++]);
				}
			}
		}
		printf("%c", currentChar);
		currentIndex++;
	}

	if (boss == 1) {
		printf("\n\nEnter your question here:\n");
		scanf("%s");
		printf("\nThinking...");
		sleep(3); 
		printf("\n\nAnswer: %s", answer);
	} 
	else {
		printf("\n\nNo, I will answer my boss only.");
		printf("\n\n\t  ENDED");
	}
	
	return 0; 
} 



