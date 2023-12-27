#include <iostream>
#include <windows.h>
#include <conio.h>  // For _getch()
#include <fstream>
#include <string>


int counter{ 0 };

int aboutPage(){

}

int settingsScreen(){
	
}

int play (int choice) {
	if (choice == 1){
	std::ifstream File("savefile.txt");
	if (File.is_open()) {
				File >> counter;
				File.close();
				Sleep(100);
			}

	}
	std::cout << "Note: You can use every key on your keyboard to click except the 'Q' Key. Have fun!\n";
	Sleep(4000);
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
				Sleep(100);
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
			Sleep(4000);
			InputChoice = 0;
			std::cin.clear();
			std::cin.ignore();
			system("cls");
			
		}
		else if (InputChoice > 4|| InputChoice < 1) { //checks if this choice even exists
			std::cout << "This choice does not exist yet :o\n";
			Sleep(4000);
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