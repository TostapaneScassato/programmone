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
string STRING_CHOICE;

// prototypes
void wait();
void gamblingMenu(bool skipAgeCheck=false);

// functions
//   utilities

class CUSTOM_OUTPUT {
public:
   void error(string parameter) {
      cerr << "[error] " << parameter;
      wait();
   }
   void title(string parameter, bool clear=true) {
      if (clear) CLEAR();
      cout << "O";
      for (int i=0; i < parameter.length()*2 + 5; i++) cout << "-";
      cout << "O" << endl << "|   ";
      
      for (int i=0; i < parameter.length(); i++) cout << parameter.at(i) << " ";
      cout << "  |" << endl << "O";

      for (int i=0; i < parameter.length()*2 + 5; i++) cout << "-";
      cout << "O" << endl << endl;
   }
   void pure (string parameter) {
      cout << parameter;
      wait();
   }
   void debug(string parameter) {
      if (DEBUG_MODE) cout << "[debug] " << parameter << endl;
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
   class RANDOM {
   public:
      int integer(int &rangeMinimum, int &rangeMaximum) {

         if (rangeMaximum < rangeMinimum) {
            int temp;
            temp = rangeMinimum;
            rangeMinimum = rangeMaximum;
            rangeMaximum = temp;
         }

         return rand()%(rangeMaximum - rangeMinimum + 1) + rangeMinimum;
      }
   };
   CUSTOM_GAMBLING::RANDOM randomGenerator;
};
CUSTOM_GAMBLING gambling;

void wait() {
   cerr << ".";
   SLEEP(300);
   cerr << ".";
   SLEEP(300);
   cerr << ".";
   SLEEP(300);
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
   cout << "[0] Go back to the main menu." << endl;
   INT_CHOICE = input.integer("> ");

   switch (INT_CHOICE) {
   case 0:
      output.pure("You'll be redirected to the main menu");
      mainMenu();
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