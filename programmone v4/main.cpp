#include <iostream>
#include <time.h>
#include <algorithm>
#include <iterator>
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
int INT_CHOICE, INT_CHOICE_2;
int playedCards[2][18]; // row 0 for dealer. row 1 for player
string STRING_CHOICE;

// prototypes
void wait();
void gamblingMenu(bool skipAgeCheck=false);
void credits();

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
   char character(char rangeMinimum, char rangeMaximum) {

      if (rangeMaximum < rangeMinimum) {
         char temp;
         temp = rangeMinimum;
         rangeMinimum = rangeMaximum;
         rangeMaximum = temp;
      }

      return rand()%(rangeMaximum - rangeMinimum + 1) + rangeMinimum;
   }
   int playingCard(int forceMark=-1, int forceSuit=-1) {
      int suit, value;

      (forceMark != -1)? value = forceMark : value = integer(1, 13);
      (forceSuit != -1)? suit = forceSuit : suit = character('A', 'D');

      if (suit == 'A') value += 100;      // spades
      else if (suit == 'B') value += 200; // clubs
      else if (suit == 'C') value += 300; // hearts
      else value += 400;                  // diamonds

      return value;
   }
};
RANDOM randomGenerator;

class CUSTOM_OUTPUT {
private:
   void printCardValue(int value, bool hidden) {
      if (hidden) cout << "??";
      else if (value == 1) cout << " A";
      else if (value == 11) cout << " J";
      else if (value == 12) cout << " Q";
      else if (value == 13) cout << " K";
      else if (value < 10) cout << "0" << value;
      else cout << value;
   }
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
   void playingCard(int value, int howManyPresent=0, bool hidden=false) {
      int mark;
      char suit;
      bool multiple = howManyPresent != 0;

      if (value > 400) {
         mark = value - 400;
         suit = 'D';
      } else if (value > 300) {
         mark = value - 300;
         suit = 'H';
      } else if (value > 200) {
         mark = value - 200;
         suit = 'C';
      } else {
         mark = value - 100;
         suit = 'S';
      }

      if (multiple) {
         cout << "\033[5A"; // move up 5 rows
         cout << "\033[" << howManyPresent*7 << "C"; // move right 7 columns for every card present
      }

      if (hidden) suit = ' ';

      cout << "O----O"; (multiple)? cout << "\033[B \033[7D" : cout << endl;                           //  O------O
      cout << "|" << suit << "  " << suit << "|"; (multiple)? cout << "\033[B \033[7D" : cout << endl; //  | S  S |
      cout << "| ";                                                                                    //  |  VV  |
      printCardValue(mark, hidden);                                                                    //  | S  S |
      cout << " |"; (multiple)? cout << "\033[B \033[7D" : cout << endl;                               //  O------O
      cout << "|" << suit << "  " << suit << "|"; (multiple)? cout << "\033[B \033[7D" : cout << endl;
      cout << "O----O" << endl;
   }
   void attention(string parameter) {
      cout << "[attention] " << parameter;
      wait();
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
private:
   int  getCardRank(int value, bool maxTen=false) {
      int rank;

      if (value > 400) rank = value - 400;
      else if (value > 300) rank = value - 300;
      else if (value > 200) rank = value - 200;
      else if (value > 100) rank = value - 100;

      if (maxTen && rank > 10) rank = 10;
      return rank;
   }
   char getCardSuit(int value) {
      char suit;

      if (value > 400) suit = 'D';
      else if (value > 300) suit = 'H';
      else if (value > 200) suit = 'C';
      else if (value > 100) suit = 'S';

      return suit;
   }
   void checkPokerHand(string player_dealer) {
      int sameSuit_spades=0, sameSuit_clubs=0, sameSuit_hearts=0, sameSuit_diamonds=0;
      int e = -1;

      if (player_dealer == "player") e = 1;
      else if (player_dealer == "dealer") e = 0;

      for (int i = 0; i < 5; i++) {

         if (getCardSuit(playedCards[e][i]) == 'S') sameSuit_spades++;
         else if (getCardSuit(playedCards[e][i]) == 'C') sameSuit_clubs++;
         else if (getCardSuit(playedCards[e][i]) == 'H') sameSuit_hearts++;
         else if (getCardSuit(playedCards[e][i]) == 'D') sameSuit_diamonds++;
      }

      int temp[5];
      for (int i=0; i<5; i++) temp[i] = playedCards[e][i];
      sort(temp, temp+5);

      bool continuous=true;
      for (int i=1; i<5; i++) if (temp[i] != temp[i-1]) continuous = false;

   };
   public:
   void blackjack() {

      playedCards[0][0] = randomGenerator.playingCard();
      playedCards[0][1] = randomGenerator.playingCard();
      int currentDealerCards = 2;
      int currentDealerValue = getCardRank(playedCards[0][0], true) + getCardRank(playedCards[0][1], true);

      playedCards[1][0] = randomGenerator.playingCard();
      playedCards[1][1] = randomGenerator.playingCard();
      int currentPlayersCards = 2;
      int currentPlayerValue = getCardRank(playedCards[1][0], true) + getCardRank(playedCards[1][1], true);
      
      output.title("BLACKJACK");
      cout << "The dealer's cards are:" << endl;

      output.playingCard(playedCards[0][0]);
      output.playingCard(playedCards[0][1], 1, true);
      
      
      cout << endl << "Your cards are:" << endl;

      output.playingCard(playedCards[1][0]);
      output.playingCard(playedCards[1][1], 1);
      
      
      do {
         cout << endl << "Would you like to draw another card or stand? (1|2): ";
         INT_CHOICE = input.integer("");

         if (INT_CHOICE == 1) {
            if (currentPlayerValue > 21) {
               cout << "You're over 21, you must stand!" << endl;
               continue;
            }

            output.playingCard(playedCards[1][0]);
   
            for (int i = 1; i < currentPlayersCards; i++) {
               output.playingCard(playedCards[1][i], i); // reprint old cards
            }

            playedCards[1][currentPlayersCards] = randomGenerator.playingCard();
            output.playingCard(playedCards[1][currentPlayersCards], true, currentPlayersCards);

            currentPlayerValue += getCardRank(playedCards[1][currentPlayersCards], true);
            currentPlayersCards++;

         } else if (INT_CHOICE == 2) {
            cout << endl << "Your count is " << currentPlayerValue << endl;
            cout << "The dealer's cards are:" << endl;
            
            output.playingCard(playedCards[0][0]);
            output.playingCard(playedCards[0][1], 1);

            while (currentDealerValue < 17) {
               cout << endl << "The dealer's value is less than 17, he draws a card." << endl;

               output.playingCard(playedCards[0][0]);
   
               for (int i = 1; i < currentDealerCards; i++) {
                  output.playingCard(playedCards[0][i], i); // reprint old cards
               }
               playedCards[0][currentDealerCards] = randomGenerator.playingCard();
               output.playingCard(playedCards[0][currentDealerCards], currentDealerCards);

               currentDealerValue += getCardRank(playedCards[0][currentDealerCards], true);
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
   void roulette() {
      int redNumbers[] = {1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36};

      output.title("ROULETTE");
      cout << "What type of bet would you like to do?" << endl;
      cout << "(a) Reds, Blacks or Green        [1-2-3]" << endl;
      cout << "(b) Evens or Odds                [4-5]" << endl;
      cout << "(c) Halves (1-18. 19-36)         [6-7]" << endl;
      cout << "(d) Thirds (1-12. 13-24. 25-36)  [8-9-10]" << endl;
      cout << "(e) Single number                [11]" << endl;
      INT_CHOICE = input.integer("> ");

      int generatedNumber = randomGenerator.integer(0, 36);

      if (INT_CHOICE == 1 && find(begin(redNumbers), end(redNumbers), generatedNumber) != end(redNumbers)) cout << "The number is " << generatedNumber << ", You Win!" << endl;
      else if (INT_CHOICE == 2 && find(begin(redNumbers), end(redNumbers), generatedNumber) == end(redNumbers)) cout << "The number is " << generatedNumber << ", You Win!" << endl;
      else if (INT_CHOICE == 3 && generatedNumber == 0) cout << "The number is " << generatedNumber << ", You Win!" << endl;
      
      else if (INT_CHOICE == 4 && generatedNumber%2 == 0) cout << "The number is " << generatedNumber << ", You Win!" << endl;
      else if (INT_CHOICE == 5 && generatedNumber%2 != 0) cout << "The number is " << generatedNumber << ", You Win!" << endl;
      
      else if (INT_CHOICE == 6 && generatedNumber > 0 && generatedNumber < 19) cout << "The number is " << generatedNumber << ", You Win!" << endl;
      else if (INT_CHOICE == 7 && generatedNumber > 18) cout << "The number is " << generatedNumber << ", You Win!" << endl;

      else if (INT_CHOICE == 8 && generatedNumber > 0 && generatedNumber < 13) cout << "The number is " << generatedNumber << ", You Win!" << endl;
      else if (INT_CHOICE == 9 && generatedNumber > 12 && generatedNumber < 25) cout << "The number is " << generatedNumber << ", You Win!" << endl;
      else if (INT_CHOICE == 10 && generatedNumber > 24) cout << "The number is " << generatedNumber << ", You Win!" << endl;

      else if (INT_CHOICE == 11) {
         do {
            cout << endl << "Please insert the number you'd like to bet on: "; 

            int numberBet = input.integer("");

            if (numberBet < 0 || numberBet > 36) {
               output.error("Please choose a valid number (0-36)");
               continue;
            } else if (numberBet == generatedNumber) {
               cout << "The number you choose was the correct one. You Win!" << endl;
               break;
            } else {
               cout << "The number was " << generatedNumber << ". You Lose!" << endl;
               break;
            }
         } while (true);

      } else if (INT_CHOICE < 12 && INT_CHOICE > 0) {
         cout << "The number was " << generatedNumber << ". You Lose!" << endl;
      } else {
         output.error("Please choose a valid option");
         roulette();
         return;
      }

      output.pure("You'll be redirected to the gambling menu");
      PAUSE();
      gamblingMenu(true);
   }
   void poker() {

      for (int i=0; i<5; i++) {playedCards[0][i] = randomGenerator.playingCard();} // generate dealer's cards
      for (int i=0; i<5; i++) {playedCards[1][i] = randomGenerator.playingCard();} // generate player's cards
      
      output.title("POKER");
      
      cout << "Dealer's cards:" << endl;

      for (int i=0; i<5; i++) {output.playingCard(playedCards[0][i], i, true);}

      cout << endl << "Your cards:" << endl;

      for (int i=0; i<5; i++) {output.playingCard(playedCards[1][i], i);}

      cout << endl << "How many cards would you like to discard? (0-5)" << endl;
      do {
         INT_CHOICE = input.integer("> ");

         if (INT_CHOICE < 0 || INT_CHOICE > 5) {
            output.error("You can only discard 0-5 cards");
            continue;
         } else break;
      } while (true);
      
      int tempArray[] = {1, 2, 3, 4, 5};

      for (int i = 0; i < INT_CHOICE; i++) {
         cout << "What card would you like to discard? (1-5)" << endl;
         INT_CHOICE_2 = input.integer("> ") - 1; // in arrays the numbers start from 0

         if (tempArray[INT_CHOICE_2] == 0) {
            output.error("Sorry, you already discarded that card");
            i--;
            continue;
         }

         playedCards[1][INT_CHOICE_2] = randomGenerator.playingCard();
         tempArray[INT_CHOICE_2] = 0;
      }

      // update the player's cards and show the dealer's cards      
      
      output.title("POKER");
      
      cout << "Dealer's cards:" << endl;

      for (int i=0; i<5; i++) {output.playingCard(playedCards[0][i], i);}

      cout << endl << "Your cards now are:" << endl;
      
      for (int i=0; i<5; i++) {output.playingCard(playedCards[1][i], i);}

      // dealer discards cards?

      bool hasRoyalFlush=0, hasStraightFlush=0, hasPoker=0, hasFullHouse=0, hasFlush=0, hasStraight=0, hasThreeOfaKind=0, hasTwoPair=0, hasPair=0;

      
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
   cout << "[9] Credits" << endl;
   cout << "[0] Exit the programmone :(" << endl;
   INT_CHOICE = input.integer("> ");

   switch (INT_CHOICE) {
   case 1:
      gamblingMenu();
      break;
   case 9:
      credits();
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
   cout << "[1] Blackjack" << endl;
   cout << "[2] Roulette" << endl;
   cout << "[3] Poker" << endl;
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
   case 2:
      gambling.roulette();
      break;
   case 3:
      output.attention("work in progress");
      //gambling.poker();
      gamblingMenu(true);
      break;
   default:
      output.error("Please insert a correct option");
      gamblingMenu(true);
      break;
   }
}

void credits() {
   output.title("CREDITS");
   
   cout << "Developers:" << endl;
   cout << "   Programmers:  - - - - - Carletti Stefano" << endl;
   cout << "   Project Manager:  - - - Carletti Stefano" << endl;
   cout << "   Code Testers: - - - - - Carletti Stefano" << endl;
   cout << "                         \\ Costi Matteo" << endl;
   cout << "                         \\ Fazioli Aurora" << endl;
   cout << "                         \\ Trotta Simone" << endl;
   cout << "Honourable Mentions:" << endl;
   cout << "   Trotta Simone:  - - - - original idea of a giant program that includes a lot of gambling games togheter" << endl;
   cout << "   Capa Suprema: - - - - - financer of the programmers' computer" << endl;
   cout << "   Di Salvo Giulia:  - - - without her boring lessons, we would have never even started this project" << endl;
   cout << "   Holy trinity: - - - - - programmers' moral support" << endl << endl;
   cout << "Copyright (c) Stefano Carletti - 2025 -- MIT License" << endl << endl;
   PAUSE();
   mainMenu();
   return;
}

// main
int main() {
   //PAUSE();
   srand(time(NULL));
   mainMenu();

   return 0;
}