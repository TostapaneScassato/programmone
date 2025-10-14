#include <iostream>
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
float REAL_CHOICE;

// prototypes
void wait();

// functions
//   utilities

class OUTPUT {
public:
   void error(string parameter) {
      cerr << "[error] " << parameter;
      wait();
   }
   void title(string parameter, bool clear) {
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
class INPUT {
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
};
//     global object
OUTPUT output;
INPUT input;

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

   output.title("MAIN MENU", true);
   cout << "Welcome to the main menu! What would you like to do?" << endl;
   cout << "[0] Exit the programmone :(" << endl;
   INT_CHOICE = input.integer("> ");


   switch (INT_CHOICE) {
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

// main
int main() {
   mainMenu();

   return 0;
}