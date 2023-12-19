#include <iostream>
#include <string>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <vector>


using namespace std;

// Hardcoded username and password
const string USERNAME = "sikandar";
const string PASSWORD = "khan2244";

void displayDateTime() {
    time_t now = time(0);
    tm* localTime = localtime(&now);

    cout << "Date: " << localTime->tm_year + 1900 << "-" << localTime->tm_mon + 1 << "-" << localTime->tm_mday << endl;
    cout << "Time: " << localTime->tm_hour << ":" << localTime->tm_min << ":" << localTime->tm_sec << endl;
}


struct Contact {
    string name;
    string phoneNumber;
    char gender;
    string address;
};

void displayContact(const Contact& contact) {
    cout << "Name: " << contact.name << endl;
    cout << "Phone Number: " << contact.phoneNumber << endl;
    cout << "Gender: " << contact.gender << endl;
    cout << "Address: " << contact.address << endl;
    cout << "---------------------------" << endl;
}

void phonebook() {
	system("cls");
    vector<Contact> phonebook;
    
    while (true) {
        cout << "Phonebook Menu:" << endl;
        cout << "1. Add a Contact" << endl;
        cout << "2. Display All Contacts" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        
        int choice;
        cin >> choice;
        
        switch (choice) {
            case 1: {
                Contact newContact;
                cout << "Enter Name: ";
                cin.ignore(); // Clear the newline character from the previous input
                getline(cin, newContact.name);
                cout << "Enter Phone Number: ";
                cin >> newContact.phoneNumber;
                cout << "Enter Gender (M/F): ";
                cin >> newContact.gender;
                cout << "Enter Address: ";
                cin.ignore();
                getline(cin, newContact.address);
                
                phonebook.push_back(newContact);
                cout << "Contact added to the phonebook." << endl;
                break;
            }
            case 2: {
                if (phonebook.empty()) {
                    cout << "Phonebook is empty." << endl;
                } else {
                    cout << "Phonebook Entries:" << endl;
                    for (vector<Contact>::const_iterator it = phonebook.begin(); it != phonebook.end(); ++it) {
                        displayContact(*it);
                    }
                }
                break;
            }
            case 3:
                cout << "Exiting the phonebook. Goodbye!" << endl;
                return;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }
}
bool isBulbOn = false;

// Function to toggle the bulb state
void toggleBulb() {
	system("cls");
    isBulbOn = !isBulbOn; // Toggle the state
    cout << (isBulbOn ? "Bulb is now ON." : "Bulb is now OFF.") <<endl;
}

// Function to play the guessing game
void playGuessingGame() {
	system("cls");
    // Seed the random number generator
    srand(static_cast<unsigned>(time(0)));

    // Generate a random number between 1 and 100
    int targetNumber = rand() % 100 + 1;
    int attempts = 0;
    int maxAttempts = 10; // You can adjust the number of attempts

    std::cout << "Welcome to the Guessing Game!" << std::endl;
    std::cout << "I'm thinking of a number between 1 and 100." << std::endl;

    while (attempts < maxAttempts) {
        int guess;
        std::cout << "Enter your guess: ";
        std::cin >> guess;

        attempts++;

        if (guess < targetNumber) {
            std::cout << "Too low! Try again." << std::endl;
        } else if (guess > targetNumber) {
            std::cout << "Too high! Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You guessed the correct number (" << targetNumber << ") in " << attempts << " attempts!" << std::endl;
            return; // End the game
        }
    }

    if (attempts >= maxAttempts) {
        std::cout << "Sorry, you've reached the maximum number of attempts. The correct number was: " << targetNumber << std::endl;
    }
}
void playMusic(const string& songTitle) {
	system("cls");
    while (true) {
        cout << "Music Menu:" << endl;
        cout << "1. Singer 1" << endl;
        cout << "2. Singer 2" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Playing music by Singer 1..." << endl;
                break;
            case 2:
                cout << "Playing music by Singer 2..." << endl;
                break;
            case 3:
                cout << "Exiting the music player. Goodbye!" << endl;
                
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }
}

int main() 
{
	cout << "          ###########################" <<endl;
    cout << "          ##  Welcome to UETM OS   ##" << endl;
    cout << "          ###########################" <<endl;
    
    // Login
    string username, password;
    do {
        cout << "Please log in:" << endl;
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;

        if (username == USERNAME && password == PASSWORD) {
            break; // Successful login
        } else {
            cout << "Invalid username or password. Please try again." << endl;
        }
    } while (true);

    // Main menu
    system("cls");
    while (true) {
        cout << "\nMain Menu" << endl;
        displayDateTime();
        cout << "1. To Run the Application" << endl;
        cout << "2. Exit" << endl;
        cout << "Enter your choice: ";
       
        int choice;
       
        cin >> choice;
        system("cls");
        displayDateTime();
        switch (choice) {
            case 1:
                // Run Application Menu
                while (true) {
                    cout << "\nApplication Menu" << endl;
                    cout << "1. Phone Book" << endl;
                    cout << "2. Applications" << endl;
                    cout << "3. Games" << endl;
                    cout << "4. Music" << endl;
                    cout << "5. Exit" << endl;
                    cout << "6. Back" << endl;
                    cout << "Enter your choice: ";
                    cin >> choice;

                    switch (choice) {
                        case 1:
                            phonebook(); //personal information
                            break;
                        case 2:
                           toggleBulb(); // Turn the bulb on
                           toggleBulb(); // Turn the bulb off
                           toggleBulb(); // Turn the bulb on
                           break;
                        case 3:
                            playGuessingGame(); // Start the game
                            break;
                        case 4:
                            playMusic("Song Title");
                            break;
                        case 5:
                            exit(0);
                        case 6:
                            break; // Return to the main menu
                        default:
                            cout << "Invalid choice. Please select a valid option." << endl;
                    }
                }
            case 2:
                exit(0);
            default:
                cout << "Invalid choice. Please select a valid option." << endl;
        }
    }

    return 0;
}
