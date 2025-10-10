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
   #define OS "linux"
   #define SLEEP(period) std::this_thread::sleep_for(std::chrono::milliseconds(period))
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

// prototypes

// utilities
void title(string title, bool clear) {
   if (clear) CLEAR();
   cout << "O";
   for (int i=0; i < title.length()*2 + 5; i++) cout << "-";
   cout << "O" << endl << "|   ";
   
   for (int i=0; i < title.length(); i++) cout << title.at(i) << " ";
   cout << "  |" << endl << "O";

   for (int i=0; i < title.length()*2 + 5; i++) cout << "-";
   cout << "O" << endl;
}

// main
int main() {

   return 0;
}