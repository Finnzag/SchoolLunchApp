#include <iostream>
#include <string>

using namespace std;

// Function definitions:
void createLoginScreen();
void createMainMenu();
void createFoodMenu();
void modifyUserAccount();
void payForItem();

// Global variables:
bool isAdmin;



int main() {
	createLoginScreen();


	return 0;
}

void createLoginScreen() {
	string username;
	string password;

	string usernameToCompare = "Finn";
	string passwordToCompare = "Password1234";
	isAdmin = false;

	cout << "School Lunch App" << endl;

	cout << "\nPlease enter your details to login\n\n";

	cout << "Please enter your username: ";
	cin >> username;
	cout << "Please enter your password: ";
	cin >> password;

	if (username == usernameToCompare && password == passwordToCompare)
	{
		createMainMenu();
	}
	else
	{
		cout << "\n\nUsername or password is incorrect. Please try again.\n\n";
		createLoginScreen();
	}

}

void createMainMenu() {
	system("cls");
	cout << "School Lunch App\n\n" << endl;
	char menuItemSelected;

	if (isAdmin)
	{
		cout << "Please select and option: \n\n";
		cout << "a. menu\n";
		cout << "b. add or edit a user\n";
		cout << "c. exit\n\n";

		cin >> menuItemSelected;

		switch (menuItemSelected)
		{
		case 'a':
			createFoodMenu();
			break;
		case 'b':
			modifyUserAccount();
			break;
		case 'c':
			exit(1);
			break;
		default:
			break;
		}
	}
	else
	{
		cout << "Please select and option: \n\n";
		cout << "a. menu\n";
		cout << "b. exit\n\n";

		cin >> menuItemSelected;

		switch (menuItemSelected)
		{
		case 'a':
			createFoodMenu();
			break;
		case 'b':
			exit(1);
			break;
		default:
			break;
		}
	}
}

void createFoodMenu() {

}

void modifyUserAccount() {

}