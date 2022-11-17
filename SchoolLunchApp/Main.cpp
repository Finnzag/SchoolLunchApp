#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

// Function declarations:
void loadUserInformation();
void writeUserInformation(string username, string password, bool adminState);
void createLoginScreen();
void createMainMenu();
void createFoodMenu(); // TODO Create a definition for this function and fill out the logic.
void modifyUserAccount();
void loadUserChangeMenu();
void createNewUser();
void payForItem(); // TODO Create a definition for this function and fill out the logic.  

// Global variables:
bool isAdmin = false;

vector<string> usernameArray{};
vector<string> passwordArray{};
vector<bool> adminStateArray{true, false};



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
	//Menu Variables
	char pizza1[] = "Cheese", pizza2[] = "Meatlovers", pizza3[] = "Supreme";
	char drinks1[] = "Sprite", drinks2[] = "Coke", drinks3[] = "Orange Juice";
	char burger1[] = "Cheese Burger", burger2[] = "Chicken Burger", burger3[] = "Fish Burger";
	char sandwich1[] = "Ham & Cheese", sandwich2[] = "Tuna & Mayo", sandwich3[] = "Meatball";
	char fried1[] = "Chicken Nuggets", fried2[] = "French Fries", fried3[] = "Onion Rings";

	char gotoBeginning;
	int foodOption;
	double qty, option = 0, pizzaPrice = 0.00, drinkPrice = 0.00, burgerPrice = 0.00, sandwichPrice = 0.00, friedPrice = 0.00;


start:
	system("cls");

	// Main Food Menu
	cout << "\n\nWhat would you like to order?\n\n";


	cout << "[1] Pizzas\n";
	cout << "[2] Burgers\n";
	cout << "[3] Sandwich\n";
	cout << "[4] Drinks\n";
	cout << "[5] Fried Food\n";
	cout << "[6] Display Total Bill\n";
	cout << "\nPlease Enter your Choice: ";
	cin >> option;

	// Pizza Options
	if (option == 1)
	{
		cout << "\n1) " << pizza1 << "\n";
		cout << "2) " << pizza2 << "\n";
		cout << "3) " << pizza3 << "\n";
		cout << "\nWhat type of pizza would you like?:";
		cin >> foodOption;

		// Pizza Size, Quantity & Price
		if (foodOption >= 1 && foodOption <= 5)
		{
			cout << "\n1) Small $5.50\n" << "2) Regular $15.25\n" << "3) Large $20.75\n";
			cout << "\nWhat size would you like?:";
			cin >> foodOption;
			if (foodOption >= 1 && foodOption <= 3)
				cout << "\nHow many would you like to order?: ";
			cin >> qty;
			switch (foodOption)
			{
			case 1: pizzaPrice = 5.50 * qty;
				break;

			case 2: pizzaPrice = 15.25 * qty;
				break;

			case 3: pizzaPrice = 20.75 * qty;
				break;


			}
			system("cls");
			switch (foodOption)
			{
			case 1:
				cout << "\t\t\t--------Your Order---------\n";
				cout << "" << qty << " x " << pizza1 << " Pizza";
				cout << "\nYour Total Bill is: $" << pizzaPrice << endl;
				break;
			case 2:
				cout << "\t\t--------Your Order---------\n";
				cout << "" << qty << " x " << pizza2 << " Pizza";
				cout << "\nYour Total Bill is: $" << pizzaPrice << endl;
				break;
			case 3:
				cout << "\t\t--------Your Order---------\n";
				cout << "" << qty << " x " << pizza3 << " Pizza";
				cout << "\nYour Total Bill is: $" << pizzaPrice << endl;
				break;

			}
			cout << "Would you like to order anything else?";
			cout << "\nPress Y to return back to menu: ";
			cin >> gotoBeginning;
			if (gotoBeginning == 'Y' || gotoBeginning == 'y')
			{
				goto start;

			}



		}

	}

	// Burger Options
	else if (option == 2)
	{
		cout << "\n1) " << burger1 << " $18.00" << "\n";
		cout << "2) " << burger2 << " $15.00" << "\n";
		cout << "3) " << burger3 << " $16.00" << "\n";
		cout << "\nWhat type of Burger you would like to have?: ";
		cin >> foodOption;

		// Burger Quantity & Price
		if (foodOption >= 1 && foodOption <= 3)
		{
			cout << "\nPlease Enter Quantity: ";
			cin >> qty;
			switch (foodOption)
			{
			case 1: burgerPrice = 18.00 * qty;
				break;

			case 2: burgerPrice = 15.00 * qty;
				break;

			case 3: burgerPrice = 16.00 * qty;
				break;

			}
			system("cls");
			switch (foodOption)
			{
			case 1:
				cout << "\t\t--------Your Order---------\n";
				cout << "" << qty << " x " << burger1;
				cout << "\nYour Total Bill is: $" << burgerPrice << endl;
				break;
			case 2:
				cout << "\t\t--------Your Order---------\n";
				cout << "" << qty << " x " << burger2;
				cout << "\nYour Total Bill is: $" << burgerPrice << endl;
				break;
			case 3:
				cout << "\t\t--------Your Order---------\n";
				cout << "" << qty << " x " << burger3;
				cout << "\nYour Total Bill is: $" << burgerPrice << endl;
				break;


			}
			cout << "\nWould you like to order anything else?";
			cout << "\nPress Y to return back to menu: ";
			cin >> gotoBeginning;
			if (gotoBeginning == 'Y' || gotoBeginning == 'y')
			{
				goto start;

			}

		}
	}

	// Sandwich Options
	else if (option == 3)
	{
		cout << "\n1)  " << sandwich1 << " $24.00" << "\n";
		cout << "2)  " << sandwich2 << " $16.00" << "\n";
		cout << "3)  " << sandwich3 << " $10.00" << "\n";
		cout << "\nWhat type Sandwich you would like to have?:";
		cin >> foodOption;

		// Sandwich Quantity & Price
		if (foodOption >= 1 && foodOption <= 3)
		{
			cout << "\nPlease Enter Quantity: ";
			cin >> qty;
			switch (foodOption)
			{
			case 1: sandwichPrice = 24.00 * qty;
				break;

			case 2: sandwichPrice = 16.00 * qty;
				break;

			case 3: sandwichPrice = 10.00 * qty;
				break;

			}
			system("cls");
			switch (foodOption)
			{
			case 1:
				cout << "\t\t--------Your Order---------\n";
				cout << "" << qty << " x " << sandwich1;
				cout << "\nYour Total Bill is : $" << sandwichPrice << endl;
				break;
			case 2:
				cout << "\t\t--------Your Order---------\n";
				cout << "" << qty << " x " << sandwich2;
				cout << "\nYour Total Bill is : $" << sandwichPrice << endl;
				break;
			case 3:
				cout << "\t\t--------Your Order---------\n";
				cout << "" << qty << " x " << sandwich2;
				cout << "\nYour Total Bill is : $" << sandwichPrice << endl;
				break;


			}
			cout << "Would you like to order anything else?";
			cout << "\nPress Y to return back to menu: ";
			cin >> gotoBeginning;
			if (gotoBeginning == 'Y' || gotoBeginning == 'y')
			{
				goto start;

			}
		}
	}

	// Drink Options
	else if (option == 4)
	{
		cout << "\n1) " << drinks1 << " $3.00" << "\n";
		cout << "2) " << drinks2 << " $3.00" << "\n";
		cout << "3) " << drinks3 << " $4.00" << "\n";
		cout << "\nWhat type of drink you would like to have?: ";
		cin >> foodOption;

		// Drink Quantity & Price
		if (foodOption >= 1 && foodOption <= 3)
		{
			cout << "\nHow many drinks would you like?: ";
			cin >> qty;
			switch (foodOption)
			{
			case 1: drinkPrice = 3.00 * qty;
				break;

			case 2: drinkPrice = 3.00 * qty;
				break;

			case 3: drinkPrice = 4.00 * qty;
				break;

			}
			system("cls");
			switch (foodOption)
			{
			case 1:
				cout << "\t\t--------Your Order---------\n";
				cout << "" << qty << " x " << drinks1;
				cout << "\nYour Total Bill is : $" << drinkPrice << endl;
				break;
			case 2:
				cout << "\t\t--------Your Order---------\n";
				cout << "" << qty << " x " << drinks2;
				cout << "\nYour Total Bill is : $" << drinkPrice << endl;
				break;
			case 3:
				cout << "\t\t--------Your Order---------\n";
				cout << "" << qty << " x " << drinks3;
				cout << "\nYour Total Bill is : $" << drinkPrice << endl;
				break;


			}
			cout << "Would you like to order anything else?";
			cout << "\nPress Y to return back to menu: ";
			cin >> gotoBeginning;
			if (gotoBeginning == 'Y' || gotoBeginning == 'y')
			{
				goto start;

			}
		}
	}

	// Fried Food Options
	else if (option == 5)
	{
		cout << "\n1) " << fried1 << " $11.00" << "\n";
		cout << "2) " << fried2 << " $7.50" << "\n";
		cout << "3) " << fried3 << " $10.25" << "\n";
		cout << "\nPlease Enter which Fried you would like to have?:";
		cin >> foodOption;

		// Fried Food Quantity & Price
		if (foodOption >= 1 && foodOption <= 3)
		{
			cout << "\nPlease Enter Quantity: ";
			cin >> qty;
			switch (foodOption)
			{
			case 1: friedPrice = 11.00 * qty;
				break;

			case 2: friedPrice = 7.50 * qty;
				break;

			case 3: friedPrice = 10.25 * qty;
				break;

			}
			system("cls");
			switch (foodOption)
			{
			case 1:
				cout << "\t\t--------Your Order---------\n";
				cout << "" << qty << " x " << fried1;
				cout << "\nYour Total Bill is : $" << friedPrice << endl;
				break;
			case 2:
				cout << "\t\t--------Your Order---------\n";
				cout << "" << qty << " x " << fried2;
				cout << "\nYour Total Bill is : $" << friedPrice << endl;
				break;
			case 3:
				cout << "\t\t--------Your Order---------\n";
				cout << "" << qty << " x " << fried3;
				cout << "\nYour Total Bill is : $" << friedPrice << endl;
				break;


			}
			cout << "Would you like to order anything else?";
			cout << "\nPress Y to return back to menu: ";
			cin >> gotoBeginning;
			if (gotoBeginning == 'Y' || gotoBeginning == 'y')
			{
				goto start;

			}
		}
	}


	else if (option == 6) {

		double totalCost = pizzaPrice + drinkPrice + burgerPrice + sandwichPrice + friedPrice;

		system("cls");

		cout << "Total order amount is: $" << totalCost << endl;
		cout << "\nPress Y to return back to menu: ";
		cin >> gotoBeginning;

		if (gotoBeginning == 'Y' || gotoBeginning == 'y')
		{
			goto start;
			return totalCost;
		}
	}
	else
	{
		system("cls");
		cout << "Invaild Selection, please choose from the options available. \n";
		cout << "Would You like to try to order again? Y / N: ";
		cin >> gotoBeginning;

		if (gotoBeginning == 'Y' || gotoBeginning == 'y')
		{
			goto start;

		}
	}

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

void modifyUserAccount() {
	
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
	}

	while (filePassword >> readInPassword)
	{
		passwordArray.push_back(readInPassword);
	}

	while (fileAdminState >> readInAdminState)
	{
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

void payForItem() {

}