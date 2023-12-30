#include <iostream>
#include <windows.h>
#include <conio.h>  // For _getch()
#include <fstream>
#include <string>


int counter{ 0 };
int time{4000};
bool disableSleep{false};

int aboutPage(){

}

int settingsScreen(){
	for(int i = 0; i < 1;){
		std::cout << "What settings would you like to change?\n\n";
		std::cout << "1. sleepValue(ms)\n";
		std::cout << "2. disableSleep\n";
		std::string input;
		std::cin >> input;
		if (input == "1" || input == "sleepValue(ms)" || input == "1. sleepValue(ms)"){  //if user chooses to change sleepValue
			std::cout << "Current value: " << time << ".\n";
			std::cout << "Change your value: ";
			std::cin >> time;
			i++;
		}
		else if (input == "2" || input == "disableSleep" || input == "2. disableSleep"){   //if user chooses to skip Sleep()
			std::cout << "Current Value: " << disableSleep << ".";
			std::cout << "Change Value(false/true|0/1): ";
			std::cin >> disableSleep;
			i++;
		}
		else{
			std::cout << "Input failed!\n";
			if(disableSleep){
					Sleep(time);
				}
			system("cls");
			std::cin.clear();
			std::cin.ignore();

		}
	}
	return 0;
}

int play (int choice) {
	if (choice == 1){
	std::ifstream File("savefile.txt");
	if (File.is_open()) {
				File >> counter;
				File.close();
				if(disableSleep){
					Sleep(time);
				}
			}

	}
	std::cout << "Note: You can use every key on your keyboard to click except the 'Q' Key. Have fun!\n";
	if(disableSleep){
		Sleep(time);
	}
	system("cls");
	char key;

	while (true) {
			// Wait for a key press
		
		key = _getch();
		system("cls");
		
			// Count the pressed key
		counter++;
		std::cout << counter;


		
		// Exit the loop if the 'q' key is pressed
		if (key == 'Q') {
			std::cout << "\nSaving file!\n";
			std::ofstream file("savefile.txt");

    	
   			if (file.is_open()) {
				file << counter;
				file.close();
				if(disableSleep){
					Sleep(time);
				}
			}
			break;
		}
	
	}
return 0;
}

int welcomeScreen() {
	std::string text = "Welcome to Cookie Clicker!\n\n";

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Get the console handle.
	PCONSOLE_SCREEN_BUFFER_INFO lpScreenInfo = new CONSOLE_SCREEN_BUFFER_INFO(); // Create a pointer to the Screen Info pointing to a temporal screen info.
	GetConsoleScreenBufferInfo(hConsole, lpScreenInfo); // Saves the console screen info into the lpScreenInfo pointer.
	COORD NewSBSize = lpScreenInfo->dwSize; // Gets the size of the screen
	if (NewSBSize.X > text.size()) {
		int newpos = ((NewSBSize.X - text.size()) / 2); // Calculate the number of spaces to center the specific text.
		for (int i = 0; i < newpos; i++) std::cout << " "; // Prints the spaces
	}
	std::cout << text << std::endl; // Prints the text centered :]
	//cookie clicker author here: Idk what this shit does but it works

	int InputChoice; //to keep track of the input 

	for (int i = 0; i < 1;) { //loop until input captured successfully
		std::cout << "\nWhat would you like to do?\n\n";
		std::cout << "1. Load previous game\n";
		std::cout << "2. Create new game\n";
		std::cout << "3. Settings\n";
		std::cout << "4. About Page\n";
		std::cout << "Choice: ";
		std::cin >> InputChoice;
		if (!std::cin) { //checks if input is a number
			std::cout << "This is not a number my friend :C\n";
			if(disableSleep){
					Sleep(time);
				}
			InputChoice = 0;
			std::cin.clear();
			std::cin.ignore();
			system("cls");
			
		}
		else if (InputChoice > 4|| InputChoice < 1) { //checks if this choice even exists
			std::cout << "This choice does not exist yet :o\n";
			if(disableSleep){
					Sleep(time);
				}
			InputChoice = 0;
			system("cls");
		}
		else {
			i++;
		}
	}
	switch (InputChoice) {  //returns value of input to main()
	case 1: return 1;
		break;
	case 2: return 2;
		break;
	case 3: return 3;
		break;
	case 4: return 4;
		break;
	}
	return 0;
}

int main() {
	for (int i = 0; i < 1;){
	int choice{ welcomeScreen() };
	std::cin.clear();
	std::cin.ignore();
		if (choice == 1 || choice == 2) {
			play(choice);
			i++;
		}
		else if (choice == 3){
			settingsScreen();
			system("cls");
		}
		else{
			aboutPage();
			system("cls");
		}
	}
}