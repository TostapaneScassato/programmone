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
int INT_CHOICE;
float REAL_CHOICE;

// prototypes

// functions
//   utilities
void title(string title, bool clear) {
   if (clear) CLEAR();
   cout << "O";
   for (int i=0; i < title.length()*2 + 5; i++) cout << "-";
   cout << "O" << endl << "|   ";
   
   for (int i=0; i < title.length(); i++) cout << title.at(i) << " ";
   cout << "  |" << endl << "O";

   for (int i=0; i < title.length()*2 + 5; i++) cout << "-";
   cout << "O" << endl << endl;
}

bool cinGood() {
   if (cin.fail()) {
      cin.clear();
      cin.ignore(9999, '\n');
      return false;
   } else
      return true;
}

void wait() {
   cerr << ".";
   SLEEP(300);
   cerr << ".";
   SLEEP(300);
   cerr << ".";
   SLEEP(300);
   return;
}

void ERROR(string parameter) {
   cerr << "[error] " << parameter;
   wait();
}
//   body
void mainMenu() {
   do {
      title("MAIN MENU", true);
      cout << "Welcome to the main menu!" << endl;
      cout << "What would you like to do?" << endl;
      cout << "[0] Exit the programmone :(" << endl;
      cout << "> "; cin >> REAL_CHOICE;

      if (!cinGood()) {
         ERROR("Insert an integer");
      }

   } while (true);

}

// main
int main() {
   mainMenu();

   return 0;
}