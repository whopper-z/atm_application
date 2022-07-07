#include <iostream>

int option;
int sendingAmount;
int withdrawAmount;
int depositAmount;
int getiban;

int balanceX = 500;
int balanceY = 450;

int xIban = 123456;
int yIban = 654321;

std::string account_1 = "x";
std::string account_1_password = "123";

std::string account_2 = "y";
std::string account_2_password = "123";


void ui() {

	std::cout << "********* BANK ********" << std::endl;
	std::cout << "1. Check Balance" << std::endl;
	std::cout << "2. Deposit" << std::endl;
	std::cout << "3. Withdraw" << std::endl;
	std::cout << "4. Send money" << std::endl;
	std::cout << "5. Logout" << std::endl;
	std::cout << "6. Exit" << std::endl;


}



int main() {
	std::string takeusername;
	std::string takepassword;

	do {
		std::cout << "Login\n" << std::endl;
		std::cout << "Username: ";
		std::cin >> takeusername;
		std::cout << "Password: ";
		std::cin >> takepassword;

		if (takeusername == account_1 && takepassword == account_1_password){
			//X
			system("cls");
			std::cout << "Welcome X." << std::endl;
			
			do{
			ui();
			std::cout << "\nOption: ";
			std::cin >> option;

			switch (option) {

			case 1: 
				system("cls");
				std::cout << "Your current balance on bank is " << balanceX << "$\n" << std::endl;; break;

			case 2: 
				system("cls");
				std::cout << "How much do you want to deposit: ";
				std::cin >> depositAmount;
				balanceX += depositAmount;
				system("cls");
				std::cout << "Succesfully deposited " << depositAmount << " to your bank account.\n" << std::endl;
				break;

			case 3:
				system("cls");
				std::cout << "How much do you want to withdraw: ";
				std::cin >> withdrawAmount;
				if (withdrawAmount <= balanceX) {
					balanceX -= withdrawAmount;
					system("cls");
					std::cout << "Withdraw was succesfull.\n" << std::endl;
					break;
				}
				else {
					system("cls");
					std::cout << "You dont have enough money to withdraw this amount.\n" << std::endl;
					break;
				
				}
			
			case 4: 
				system("cls");
				std::cout << "Enter a iban to send money: ";
				std::cin >> getiban;
				std::cout << "Amount: ";
				std::cin >> sendingAmount;

				if (getiban == xIban) {
					system("cls");
					std::cout << "You cant send money to yourself. bakaaa!\n" << std::endl; break;
				}


				else if (sendingAmount > balanceX){
					system("cls");
					std::cout << "You dont have enough money. bakaaa!\n" << std::endl; break;
				}


				else if (getiban == yIban) {

					balanceX -= sendingAmount;
					balanceY += sendingAmount;
					system("cls");
					std::cout << "Succesfully sended "<< sendingAmount << " to " << account_2 << "\n" << std::endl; break;
					
					
				}
				else {

					system("cls");
					std::cout << "Theres no such iban.\n" << std::endl; break;
				}

			case 5: 
				system("cls");
				main();



			}
			} while (option != 6);
			

		}

		else if (takeusername == account_2 && takepassword == account_2_password) {
			//mert
			system("cls");
			std::cout << "Welcome Y." << std::endl;
			do {
				ui();
				std::cout << "\nOption: ";
				std::cin >> option;

				switch (option) {

				case 1:
					system("cls");
					std::cout << "Your current balance on bank is " << balanceY << "$\n" << std::endl;; break;

				case 2:
					system("cls");
					std::cout << "How much do you want to deposit: ";
					std::cin >> depositAmount;
					balanceY += depositAmount;
					system("cls");
					std::cout << "Succesfully deposited " << depositAmount << " to your bank account.\n" << std::endl;
					break;

				case 3:
					system("cls");
					std::cout << "How much do you want to withdraw: ";
					std::cin >> withdrawAmount;
					if (withdrawAmount <= balanceY) {
						balanceY -= withdrawAmount;
						system("cls");
						std::cout << "Withdraw was succesfull.\n" << std::endl;
						break;
					}
					else {
						system("cls");
						std::cout << "You dont have enough money to withdraw this amount.\n" << std::endl;
						break;

					}

				case 4:
					system("cls");
					std::cout << "Enter a iban to send money: ";
					std::cin >> getiban;
					std::cout << "Amount: ";
					std::cin >> sendingAmount;

					if (getiban == yIban) {
						system("cls");
						std::cout << "You cant send money to yourself. bakaaa!\n" << std::endl; break;
					}


					else if (sendingAmount > balanceY) {
						system("cls");
						std::cout << "You dont have enough money. bakaaa!\n" << std::endl; break;
					}


					else if (getiban == xIban) {

						balanceY -= sendingAmount;
						balanceX += sendingAmount;
						system("cls");
						std::cout << "Succesfully sended " << sendingAmount << " to " << account_1 << "\n" << std::endl; break;


					}
					else {

						system("cls");
						std::cout << "Theres no such iban.\n" << std::endl; break;
					}

				case 5:
					system("cls");
					main();



				}
			} while (option != 6);

		}
		else {
			system("cls");
			std::cout << "Username or Password is wrong.\n" << std::endl;
		}




	} while (takeusername != account_1 && takepassword != account_1_password || takeusername != account_2 && takepassword != account_2_password);



}



