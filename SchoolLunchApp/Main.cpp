#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

// Function declarations:
void loadUserInformation();
void writeUserInformation(string username, string password, bool adminState);
void saveUserDataOnExit(string username, string password, bool adminState, int runID);
void createLoginScreen();
void createMainMenu();
void createFoodMenu(); // TODO Create a definition for this function and fill out the logic.
void modifyUserAccount();
void changeAccountData(string& username, int userID);
void loadUserChangeMenu();
void createNewUser();
void payForItem(); // TODO Create a definition for this function and fill out the logic.  

// Global variables:
bool isAdmin = false;

vector<string> usernameArray{};
vector<string> passwordArray{};
vector<bool> adminStateArray{};



int main() {

	loadUserInformation();

	createLoginScreen();

	return 0;
}

void createLoginScreen() {
	string username;
	string password;

	string usernameToCompare = "Finn";
	string passwordToCompare = "Password1234";


	cout << "School Lunch App" << endl;

	cout << "\nPlease enter your details to login\n\n";

	cout << "Please enter your username: ";
	cin >> usernameToCompare;
	cout << "Please enter your password: ";
	cin >> passwordToCompare;

	for (size_t i = 0; i < usernameArray.size(); i++)
	{
		if (usernameToCompare == usernameArray[i])
		{
			if (passwordToCompare == passwordArray[i])
			{
				isAdmin = adminStateArray[i];
				createMainMenu();
			}
			else
			{
				cout << "\n\nUsername or password is incorrect. Please try again.\n\n";
				createLoginScreen();
			}
		}

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
			loadUserChangeMenu();
			break;
		case 'c':
			for (size_t i = 0; i < usernameArray.size(); i++)
			{
				saveUserDataOnExit(usernameArray[i], passwordArray[i], adminStateArray[i], i);
			}
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

void loadUserChangeMenu() {
	char menuSelection = ' ';

	system("cls");

	cout << "School Lunch App" << endl;

	cout << "Would you like to create or modify an account ?\n\n";

	cout << "a. Create new account\n";
	cout << "b. Modify Existing account\n\n";
	cin >> menuSelection;

	switch (menuSelection)
	{
	case 'a':
		createNewUser();
		break;
	case 'b':
		modifyUserAccount();
		break;
	default:
		break;
	}
}

void changeAccountData(string& username, int userID) {
	system("cls");

	char menuSelection;
	string newUsername;
	string newPassword;
	bool newAdminState;

	cout << "School Lunch App" << endl;

	if (username == usernameArray[userID]) {
		cout << "Please select what you would like to change: \n";
		cout << "a. Username\n";
		cout << "b. Password\n";
		cout << "c. Admin State\n";

		cin >> menuSelection;

		switch (menuSelection)
		{
		case 'a':
			cout << "\nPlease enter the new username: \n";
			cin >> newUsername;
			usernameArray[userID] = newUsername;
			createMainMenu();
			break;
		case 'b':
			cout << "\nPlease enter the new password: \n";
			cin >> newPassword;
			passwordArray[userID] = newPassword;
			createMainMenu();
			break;
		case 'c':
			cout << "\n Please enter a new admin state: \n";
			cin >> newAdminState;
			adminStateArray[userID] = newAdminState;
			createMainMenu();
			break;
		default:
			changeAccountData(username, userID);
			break;
		}
	}
}

void modifyUserAccount() {
	string userToBeChanged = " ";

	cout << "School Lunch App" << endl;

	cout << "\n Please enter the name of the uer you would like to change: \n";
	cin >> userToBeChanged;

	for (size_t i = 0; i < usernameArray.size(); i++)
	{
		cout << i;
		if (userToBeChanged == usernameArray[i]) {
			cout << usernameArray[i];
			changeAccountData(userToBeChanged, i);

		}
		else if (i >= usernameArray.size())
		{
			cout << "User could not be found. Please Try again.\n";
			modifyUserAccount();

		}
	}
}

void createNewUser() {

	string username = " ";
	string password = " ";
	bool adminStatus = false;


	cout << "School Lunch App" << endl;

	cout << "\n Please enter the account username: ";
	cin >> username;
	cout << "\n Please enter a password: ";
	cin >> password;
	cout << "\n Is this user an admin ? True(1) or false (0): ";
	cin >> adminStatus;

	usernameArray.push_back(username);
	passwordArray.push_back(password);
	adminStateArray.push_back(adminStatus);

	writeUserInformation(username, password, adminStatus);

	cout << "\n\n Would you like tot create another user ? Y or N";


}

void loadUserInformation() {
	// Variabless to temporarily store the username data
	string readInUsername;
	string readInPassword;
	bool readInAdminState;

	// Open the files that contain the user data
	ifstream fileUsername("username");
	ifstream filePassword("password");
	ifstream fileAdminState("adminState");

	// Transfer the user infiormation from the temp variables to their resptive arrays
	while (fileUsername >> readInUsername)
	{
		usernameArray.push_back(readInUsername);
		filePassword >> readInPassword;
		passwordArray.push_back(readInPassword);
		fileAdminState >> readInAdminState;
		adminStateArray.push_back(readInAdminState);
	}
}

void writeUserInformation(string username, string password, bool adminState) {
	ofstream usernameFile;
	ofstream passwordFile;
	ofstream adminStateFile;

	usernameFile.open("username", ios::out | ios::ate | ios::app);
	passwordFile.open("password", ios::out | ios::ate | ios::app);
	adminStateFile.open("adminState", ios::out | ios::ate | ios::app);

	usernameFile << endl << username;
	passwordFile << endl << password;
	adminStateFile << endl <<  adminState;

	usernameFile.close();
	passwordFile.close();
	adminStateFile.close();

}

void saveUserDataOnExit(string username, string password, bool adminState, int runID) {
	ofstream usernameFile;
	ofstream passwordFile;
	ofstream adminStateFile;

	if (runID > 0)
	{
		usernameFile.open("username", ios::out | ios::ate | ios::app);
		passwordFile.open("password", ios::out | ios::ate | ios::app);
		adminStateFile.open("adminState", ios::out | ios::ate | ios::app);
	}
	else
	{
		usernameFile.open("username", ios::trunc | ios::out | ios::ate);
		passwordFile.open("password", ios::trunc | ios::out | ios::ate);
		adminStateFile.open("adminState", ios::trunc | ios::out | ios::ate);
	}

	

	usernameFile << endl << username;
	passwordFile << endl << password;
	adminStateFile << endl << adminState;

	usernameFile.close();
	passwordFile.close();
	adminStateFile.close();
}
void payForItem() {

}