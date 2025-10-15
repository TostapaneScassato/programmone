#include <iostream>
#include <time.h>
using namespace std;
#define PROGRAMMONE_VERSION 4

// preprocessor
#ifdef _WIN32
   #define byte win_byte_override
   #include <windows.h>
   #undef byte
   #define OS "windows"
   #define SLEEP(period) Sleep(period)
   #define CLEAR() system("cls")
   #define PAUSE() system("pause")
#elif __linux__
   #include <unistd.h>
   #include <thread>
   #include <chrono>
   #define OS "linux"
   #define SLEEP(period_milliseconds) std::this_thread::sleep_for(std::chrono::milliseconds(period_milliseconds))
   #define CLEAR() system("clear")
   #define PAUSE() system("read -n 1 -s -r -p \"Press a key to continue...\"")
#elif __APPLE__
   cout << "Hmm. I see you're using Apple. No\n";
   return EXIT_FAILURE;
#elif __ANDOIRD__
   cout << "I don't feel like porting this to Android. Next time use a real Linux distro\n";
   return EXIT_FAILURE:
#else
   cerr << "[catastrophic failure] I couldn't determine you're Operating System!\n";
   return EXIT_FAILURE;
#endif

// global variables
bool DEBUG_MODE = false;
int INT_CHOICE;
int playedCards[2][18]; // row 0 for dealer. row 1 for player
string STRING_CHOICE;

// prototypes
void wait();
void gamblingMenu(bool skipAgeCheck=false);

// functions
//   utilities

class RANDOM {
public:
   int integer(int rangeMinimum, int rangeMaximum) {

      if (rangeMaximum < rangeMinimum) {
         int temp;
         temp = rangeMinimum;
         rangeMinimum = rangeMaximum;
         rangeMaximum = temp;
      }

      return rand()%(rangeMaximum - rangeMinimum + 1) + rangeMinimum;
   }
};
RANDOM randomGenerator;

class CUSTOM_OUTPUT {
public:
   void error(string parameter) {
      cerr << "[error] " << parameter;
      wait();
   }
   void title(string parameter, bool clear=true) {
      if (clear) CLEAR();
      cout << "88";
      for (int i=0; i < parameter.length()*2 + 5; i++) cout << "=";
      cout << "88" << endl << "||   ";
      
      for (int i=0; i < parameter.length(); i++) cout << parameter.at(i) << " ";
      cout << "  ||" << endl << "88";

      for (int i=0; i < parameter.length()*2 + 5; i++) cout << "=";
      cout << "88" << endl << endl;
   }
   void pure (string parameter) {
      cout << parameter;
      wait();
   }
   void debug(string parameter) {
      if (DEBUG_MODE) cout << "[debug] " << parameter << endl;
   }
   int randomPlayingCard(bool multiple=false, int howManyPresent=0, bool hidden=false, int forceValue=-1) {
      int value;
      
      (forceValue != -1)? value = forceValue : value = randomGenerator.integer(1, 13);

      if (multiple) {
         cout << "\033[5A"; // move up 5 rows
         cout << "\033[" << howManyPresent*7 << "C"; // move right 7 columns for every card present
      }

      cout << "O----O"; (multiple)? cout << "\033[B \033[7D" : cout << endl;
      cout << "|    |"; (multiple)? cout << "\033[B \033[7D" : cout << endl;
      cout << "| ";

      if (hidden) cout << "??";
      else if (value == 1) cout << " A";
      else if (value == 11) cout << " J";
      else if (value == 12) cout << " Q";
      else if (value == 13) cout << " K";
      else if (value < 10) cout << "0" << value;
      else cout << value;
      
      cout << " |"; (multiple)? cout << "\033[B \033[7D" : cout << endl;
      cout << "|    |"; (multiple)? cout << "\033[B \033[7D" : cout << endl;
      cout << "O----O" << endl;
      
      if (value > 10) value = 10;

      return value;
   }
};
CUSTOM_OUTPUT output;

class CUSTOM_INPUT {
public:
   int integer(string request) {
      float real;
      int parameter;

      do {
         cout << request;  cin >> real;

         if (cin.fail()) {
            cin.clear();
            cin.ignore(9999, '\n');
            continue;
         }

         parameter = int(real);

         if (float(parameter) != real) continue;
         else break;

      } while (true);
      
      return parameter;
   }
   string letters(string request) {
      cout << request;  cin >> STRING_CHOICE;
      return STRING_CHOICE;
   }
};
CUSTOM_INPUT input;

class CUSTOM_GAMBLING {
public:
   void blackjack() {
      
      output.title("BLACKJACK");
      cout << "The dealer's cards are:" << endl;
      playedCards[0][0] = output.randomPlayingCard();
      playedCards[0][1] = output.randomPlayingCard(true, 1, true); // second hidden card
      
      int currentDealerCards = 2;
      int currentDealerValue = playedCards[0][0] + playedCards[0][1];
      
      cout << endl << "Your cards are:" << endl;
      playedCards[1][0] = output.randomPlayingCard();
      playedCards[1][1] = output.randomPlayingCard(true, 1);
      
      int currentPlayersCards = 2;
      int currentPlayerValue = playedCards[1][0] + playedCards[1][1];
      
      do {
         cout << endl << "Would you like to draw another card or stand? (1|2): ";
         INT_CHOICE = input.integer("");

         if (INT_CHOICE == 1) {
            if (currentPlayerValue > 21) {
               cout << "You're over 21, you must stand!" << endl;
               continue;
            }

            output.randomPlayingCard(false, 0, false, playedCards[1][0]);
   
            for (int i = 1; i < currentPlayersCards; i++) {
               output.randomPlayingCard(true, i, false, playedCards[1][i]); // re-print old cards
            }
   
            playedCards[1][currentPlayersCards] = output.randomPlayingCard(true, currentPlayersCards, false);
            currentPlayerValue += playedCards[1][currentPlayersCards];
            currentPlayersCards++;

         } else if (INT_CHOICE == 2) {
            cout << endl << "Your count is " << currentPlayerValue << endl;
            cout << "The dealer's cards are:" << endl;
            
            output.randomPlayingCard(false, 0, false, playedCards[0][0]);
            output.randomPlayingCard(true, 1, false, playedCards[0][1]);

            while (currentDealerValue < 17) {
               cout << endl << "The dealer's value is less than 17, he draws a card." << endl;

               output.randomPlayingCard(false, 0, false, playedCards[0][0]);
   
               for (int i = 1; i < currentDealerCards; i++) {
                  output.randomPlayingCard(true, i, false, playedCards[0][i]); // re-print old cards
               }
               playedCards[0][currentDealerCards] = output.randomPlayingCard(true, currentDealerCards, false);
               currentDealerValue += playedCards[0][currentDealerCards];
               currentDealerCards++;
            }
            break;
         }
      } while (true);

      cout << endl;
      output.title("results", false);

      cout << "Your total value: " << currentPlayerValue << endl;
      cout << "Dealer's total value: " << currentDealerValue << endl << endl;

      if (currentPlayerValue > 21) {
         cout << "You went over 21. You Lose!" << endl;
         output.pure("You'll be redirected to the gambling menu");
         PAUSE();
         gamblingMenu(true);
         return;
      }
      else if (currentPlayerValue == 21) cout << "You have a Blackjack!" << endl;

      if (currentDealerValue > 21) {
         cout << "The dealer went over 21. You Win!" << endl;
         output.pure("You'll be redirected to the gambling menu");
         PAUSE();
         gamblingMenu(true);
         return;
      }

      if (currentPlayerValue > currentDealerValue) {
         cout << "Your value is higher. You Win!" << endl;
         output.pure("You'll be redirected to the gambling menu");
         PAUSE();
         gamblingMenu(true);
         return;
      } else if (currentPlayerValue < currentDealerValue) {
         cout << "The dealer has a higher value. You Lose!" << endl;
         output.pure("You'll be redirected to the gambling menu");
         PAUSE();
         gamblingMenu(true);
         return;
      } else {
         cout << "You and the dealer have the same value. It's a Tie!" << endl;
         output.pure("You'll be redirected to the gambling menu");
         PAUSE();
         gamblingMenu(true);
         return;
      }
   }
};
CUSTOM_GAMBLING gambling;

void wait() {
   cerr << ".";
   SLEEP(300);
   cerr << ".";
   SLEEP(300);
   cerr << ".";
   SLEEP(300);
   cout << endl;
   return;
}

//   body
void mainMenu() {

   output.title("MAIN MENU");
   cout << "Welcome to the main menu! What would you like to do?" << endl;
   cout << "[1] Gambling games (18+)" << endl;
   cout << "[0] Exit the programmone :(" << endl;
   INT_CHOICE = input.integer("> ");

   switch (INT_CHOICE) {
   case 1:
      gamblingMenu();
      break;
   case 0:
      output.pure("Bye bye, come back soon!");
      return;
      break;
   default:
      output.error("Insert a correct option");
      mainMenu();
      break;
   }

}

void gamblingMenu(bool skipAgeCheck) {
   if (!skipAgeCheck) {
      output.title("Are you 18 or older? (yes/no)");
      if (input.letters("> ") != "yes") {
         output.pure("You'll be redirected to the main menu");
         mainMenu();
         return;
      }
   }
   
   output.title("GAMBLING MENU");
   cout << "Welcome to the gambling menu, what game would you like to play?" << endl;
   cout << "[1] Blackjack." << endl;
   cout << "[0] Go back to the main menu." << endl;
   INT_CHOICE = input.integer("> ");

   switch (INT_CHOICE) {
   case 0:
      output.pure("You'll be redirected to the main menu");
      mainMenu();
      break;
   case 1:
      gambling.blackjack();
      break;
   default:
      output.error("Please insert a correct option");
      gamblingMenu(true);
      break;
   }
}

// main
int main() {
   //PAUSE();
   srand(time(NULL));
   mainMenu();

   return 0;
}