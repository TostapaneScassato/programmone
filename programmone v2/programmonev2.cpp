#include <iostream>
#include <windows.h>
#include <algorithm>
using namespace std;

bool debugMode=false;

void menu();
void roulette();
void impostazioni();
void regole();

void wait() { // - - - - - - - - - - - - - - - - - - - - - - - - - - aspetta e stampa '...'  --  --  --  --  --  --  --  --  --  - COMPLETATO
    Sleep(300);
    cout << ".";
    Sleep(300);
    cout << ".";
    Sleep(300);
    cout << ".";
    Sleep(300);
    return;
}

void debugLogin() {//- - - - - - - - - - - - - - - - - - - - - - - - meccanismi di attivatione/disattivazione debugMode  --  --  - COMPLETATO
    system("cls");
    int scelta;
    string password;

    cout << "O-------------------------O" << endl;
    cout << "|   D E B U G   M O D E   |" << endl;
    cout << "O-------------------------O" << endl;
    cout << " " << endl;
    cout << "Attualmente la DebugMode e' impostata a " << debugMode << endl;
    
    if (!debugMode) {
        cout << "- 1: Attivala" << endl;
        cout << "- 0: Torna al menu delle impostazioni" << endl;
        cout << "Scelta: ";
        cin >> scelta;

        switch (scelta) {
        case 1:
            cout << "Per attivarla, devi inserire la password: ";
            cin >> password;

            if (password == "3791796801") {
                debugMode = true;
                cout << "La debugMode e' stata attivata con successo";
                wait();
                impostazioni();
                break;
            } else {
                cout << "ATTENZIONE: Inserire la password corretta";
                wait();
                debugLogin();
                break;
            }
            break;
        case 0:
            cout << "Verrai reindirizzato al menu delle impostazioni";
            wait();
            impostazioni();
            break;
        default:
            cout << "ATTENZIONE: Inserire un'opzione accettabile";
            wait();
            debugLogin();
            break;
        }
    } else {
        cout << "- 1: Disattivala" << endl;
        cout << "- 0: Torna al menu delle impostazioni" << endl;
        cout << "Scelta: ";
        cin >> scelta;

        switch (scelta) {
        case 1:
            cout << "Per disattivarla, devi inserire la password: ";
            cin >> password;

            if (password == "3791796801") {
                debugMode = false;
                cout << "La debugMode e' stata disattivata con successo";
                wait();
                impostazioni();
                break;
            } else {
                cout << "ATTENZIONE: Inserire la password corretta";
                wait();
                debugLogin();
                break;
            }
            break;
        case 0:
            cout << "Verrai reindirizzato al menu delle impostazioni";
            wait();
            impostazioni();
            break;
        default:
            cout << "ATTENZIONE: Inserire un'opzione accettabile";
            wait();
            debugLogin();
            break;
        }
    }

}

void slot() { // - - - - - - - - - - - - - - - - - - - - - - - - - - meccanismi slot --  --  --  --  --  --  --  --  --  --  --  - COMPLETATO
    system("cls");
    srand(time(NULL));
    int numero1, numero2, numero3;
    char scelta;
    bool running=true;

    cout << "O-----------------------------O" << endl;
    cout << "|   S L O T   M A C H I N E   |" << endl;
    cout << "O-----------------------------O" << endl;

    while (running) {
        numero1 = (rand()%9);
        numero2 = (rand()%9);
        numero3 = (rand()%9);

        cout << "I tuoi numeri sono:    || " << numero1 << " - " << numero2 << " - " << numero3 << " ||" << endl << endl;

        if ((numero1 == numero2) && (numero2 == numero3) && (numero1 == 7)) {
            cout << "Complimenti! Hai vinto il jackpot!" << endl;
            cout << "Vorresti rigirare? (s/n)";
            cin >> scelta;
            switch (scelta) {
            case 's':
                cout << endl;
                break;
            case 'S':
                cout << endl;
                break;
            case 'n':
                cout << "Ok, verrai reindirizzato al menù principale";
                running = false;
                wait();
                menu();
                break;
            case 'N':
                cout << "Ok, verrai reindirizzato al menu principale";
                running = false;
                wait();
                menu();
                break;
            default:
                cout << "ATTENZIONE: Inserire un'opzione accettabile";
                running = false;
                wait();
                slot();
                break;
            }
        } else if ((numero1 == numero2) && (numero2 == numero3)) {
            cout << "Complimenti, hai vinto il mini-jackpot!" << endl;
            cout << "Vorresti rigirare? (s/n)";
            cin >> scelta;
            switch (scelta) {
            case 's':
                cout << endl;
                break;
            case 'S':
                cout << endl;
                break;
            case 'n':
                cout << "Ok, verrai reindirizzato al menù principale";
                running = false;
                wait();
                menu();
                break;
            case 'N':
                cout << "Ok, verrai reindirizzato al menu principale";
                running = false;
                wait();
                menu();
                break;
            default:
                cout << "ATTENZIONE: Inserire un'opzione accettabile";
                running = false;
                wait();
                slot();
                break;
            }
        } else {
            cout << "Peccato, andra' meglio la prossima volta!" << endl;
            cout << "Vorresti rigirare? (s/n) ";
            cin >> scelta;
            switch (scelta) {
                case 's':
                    cout << endl;
                    break;
                case 'S':
                    cout << endl;
                    break;
                case 'n':
                    cout << "Ok, verrai reindirizzato al menu principale";
                    running = false;
                    wait();
                    menu();
                    break;
                case 'N':
                    cout << "Ok, verrai reindirizzato al menu principale";
                    running = false;
                    wait();
                    menu();
                    break;
                default:
                    cout << "ATTENZIONE: Inserire un'opzione accettabile";
                    running = false;
                    wait();
                    slot();
                    break;
            }
        }
    }
}

void roulette_caso1() { // - - - - - - - - - - - - - - - - - - - - - roulette se pari o dispari  --  --  --  --  --  --  --  --  - COMPLETATO
    srand(time(NULL));
    system("cls");
    int scelta, numero;

    numero = rand()%2;

    if (debugMode) { //- - - - - - - - - - - - - - - - - - - - - - - debug
        cout << "DEBUG: il numero e' " << numero << endl;
    }

    cout << "O---------------------O" << endl;
    cout << "|   R O U L E T T E   |" << endl;
    cout << "O---------------------O" << endl;
    cout << " " << endl;
    cout << "Vorresti scommettere sui pari o sui dispari?" << endl;
    cout << "- 1: Dispari" << endl;
    cout << "- 2: Pari" << endl;
    cout << "- 0: Torna al menu della roulette" << endl;
    cout << "Scelta: ";
    cin >> scelta;

    if (((numero == 0) && (scelta == 2)) || ((numero == 1) && (scelta == 1))) {
        cout << "Complimenti, hai vinto!" << endl;
        cout << "Ora verrai reindirizzato al menu della roulette";
        wait();
        roulette();
    } else if (scelta == 0) {
        cout << "Verrai reindirizzato al menu della roulette";
        wait();
        roulette();
    } else if ((scelta == 1) || (scelta == 2)) {
        cout << "Peccato, hai perso!" << endl;
        cout << "Ora verrai reindirizzato al menu della roulette";
        wait();
        roulette();
    } else {
        cout << "ATTENZIONE: Inserire un numero accettabile";
        wait();
        roulette_caso1();
    }
}
void roulette_caso2() { // - - - - - - - - - - - - - - - - - - - - - roulette se neri o rossi -  --  --  --  --  --  --  --  --  - COMPLETATO
    srand(time(NULL));
    system("cls");
    int scelta, numero;

    numero = rand()%2;

    if (debugMode) { //- - - - - - - - - - - - - - - - - - - - - - - debug
        cout << "DEBUG: il numero e' " << numero << endl;
    }

    cout << "O---------------------O" << endl;
    cout << "|   R O U L E T T E   |" << endl;
    cout << "O---------------------O" << endl;
    cout << " " << endl;
    cout << "Vorresti scommettere sui neri o sui rossi?" << endl;
    cout << "- 1: Rossi" << endl;
    cout << "- 2: Neri" << endl;
    cout << "- 0: Torna al menu della roulette" << endl;
    cout << "Scelta: ";
    cin >> scelta;

    if (((scelta == 1) && (numero == 0)) || ((scelta == 2) && (numero == 1))) {
        cout << "Complimenti, hai vinto!" << endl;
        cout << "Ora verrai reindirizzato al menu della roulette";
        wait();
        roulette();
    } else if (scelta == 0) {
        cout << "Ora verrai reindirizzato al menu della roulette";
        wait();
        roulette();
    } else if ((scelta == 1) || (scelta == 2)) {
        cout << "Peccato, hai perso!" << endl;
        cout << "Ora verrai reindirizzato al menu della roulette";
        wait();
        roulette();
    } else {
        cout << "ATTENZIONE: Inserire un numero accettabile";
        wait();
        roulette_caso2();
    }
}
void roulette_caso3() { // - - - - - - - - - - - - - - - - - - - - - roulette se numero spec --  --  --  --  --  --  --  --  --  - COMPLETATO
    srand(time(NULL));
    system("cls");
    int scelta, numero;

    numero = rand()%36 + 1;

    if (debugMode) { //- - - - - - - - - - - - - - - - - - - - - - - debug
        cout << "DEBUG: il numero e' " << numero << endl;
    }

    cout << "O---------------------O" << endl;
    cout << "|   R O U L E T T E   |" << endl;
    cout << "O---------------------O" << endl;
    cout << " " << endl;
    cout << "Indica il numero su cui vuoi scommettere (inserire '40' per tornare al menu della roulette): ";
    cin >> scelta;

    if (numero == scelta) {
        cout << "Complimenti, hai vinto!" << endl;
        cout << "Verrai reindirizzato al menu della roulette";
        wait();
        roulette();
    } else if (scelta == 40) {
        cout << "Verrai reindirizzatto al menu della roulette";
        wait();
        roulette();
    } else if ((scelta < 37) && (scelta > 0)) {
        cout << "Peccato, hai perso!" << endl;
        cout << "Verrai reindirizzato al menu della roulette";
        wait();
        roulette();
    } else {
        cout << "ATTENZIONE: Inserire un numero accettabile";
        wait();
        roulette_caso3();
    }
}
void roulette_caso4() { // - - - - - - - - - - - - - - - - - - - - - roulette se alto o basso -  --  --  --  --  --  --  --  --  - COMPLETATO
    srand(time(NULL));
    system("cls");
    int scelta, numero;

    numero = rand()%2;

    if (debugMode) { //- - - - - - - - - - - - - - - - - - - - - - - debug
        cout << "DEBUG: il numero e' " << numero << endl;
    }

    cout << "O---------------------O" << endl;
    cout << "|   R O U L E T T E   |" << endl;
    cout << "O---------------------O" << endl;
    cout << " " << endl;
    cout << "Vorresti scommettere sui numeri bassi (1-18) o sui numeri alti (19-36)?" << endl;
    cout << "- 1: Alti" << endl;
    cout << "- 2: Bassi" << endl;
    cout << "- 0: Torna al menu della roulette" << endl;
    cout << "Scelta: ";
    cin >> scelta;

    if (((scelta == 1) && (numero == 0)) || ((scelta == 2) && (numero == 1))) {
        cout << "Complimenti, hai vinto!" << endl;
        cout << "Ora verrai reindirizzato al menu della roulette";
        wait();
        roulette();
    } else if (scelta == 0) {
        cout << "Ora verrai reindirizzato al menu della roulette";
        wait();
        roulette();
    } else if ((scelta == 1) || (scelta == 2)) {
        cout << "Peccato, hai perso!" << endl;
        cout << "Ora verrai reindirizzato al menu della roulette";
        wait();
        roulette();
    } else {
        cout << "ATTENZIONE: Inserire un numero accettabile";
        wait();
        roulette_caso4();
    }
}
void roulette_caso5() { // - - - - - - - - - - - - - - - - - - - - - roulette se dozzine  -  --  --  --  --  --  --  --  --  --  - COMPLETATO
    srand(time(NULL));
    system("cls");
    int scelta, numero;

    numero = rand()%3;

    if (debugMode) { //- - - - - - - - - - - - - - - - - - - - - - - debug
        cout << "DEBUG: il numero e' " << numero << endl;
    }

    cout << "O---------------------O" << endl;
    cout << "|   R O U L E T T E   |" << endl;
    cout << "O---------------------O" << endl;
    cout << " " << endl;
    cout << "Su che dozzina vorresti scommettere?" << endl;
    cout << "- 1: Prima dozzina (1-12)" << endl;
    cout << "- 2: Seconda dozzina (13-24)" << endl;
    cout << "- 3: Terza dozzina (25-36)" << endl;
    cout << "- 0: Torna al menu della roulette" << endl;
    cout << "Scelta: ";
    cin >> scelta;

    if (((scelta == 1) && (numero == 0)) || ((scelta == 2) && (numero == 1)) || ((scelta == 3) && (numero == 2))) {
        cout << "Complimenti, hai vinto!" << endl;
        cout << "Ora verrai reindirizzato al menu della roulette";
        wait();
        roulette();
    } else if (scelta == 0) {
        cout << "Ora verrai reindirizzato al menu della roulette";
        wait();
        roulette();
    } else if ((scelta == 1) || (scelta == 2) || (scelta == 3)) {
        cout << "Peccato, hai perso!" << endl;
        cout << "Ora verrai reindirizzato al menu della roulette";
        wait();
        roulette();
    } else {
        cout << "ATTENZIONE: Inserire un numero accettabile";
        wait();
        roulette_caso5();
    }
}

void roulette() { // - - - - - - - - - - - - - - - - - - - - - - - - meccanismi roulette --  --  --  --  --  --  --  --  --  --  - COMPLETATO

    system("cls");
    int scelta;

    cout << "O---------------------O" << endl;
    cout << "|   R O U L E T T E   |" << endl;
    cout << "O---------------------O" << endl;
    cout << " " << endl;
    cout << "Su cosa vorresti scommettere?" << endl;
    cout << "- 1: Pari o Dispari" << endl;
    cout << "- 2: Neri o Rossi" << endl;
    cout << "- 3: Numero Specifico" << endl;
    cout << "- 4: Alto o Basso" << endl;
    cout << "- 5: Dozzine" << endl;
    cout << "- 0: Torna al menu principale" << endl;
    cout << "Scelta: ";
    cin >> scelta;

    switch (scelta) {
        case 1:
            roulette_caso1();
            break;
        case 2:
            roulette_caso2();
            break;
        case 3:
            roulette_caso3();
            break;
        case 4:
            roulette_caso4();
            break;
        case 5:
            roulette_caso5();
            break;
        case 0:
            cout << "Ok, verrai reindirizzato al menu principale";
            wait();
            menu();
            break;
        default:
            cout << "ATTENZIONE: Inserire un opzione accettabile";
            wait();
            roulette();
            break;
    }
}

void dadi() { // - - - - - - - - - - - - - - - - - - - - - - - - - - meccanismi dadi --  --  --  --  --  --  --  --  --  --  --  - COMPLETATO
    system("cls");
    srand(time(NULL));
    int scelta, dado1, dado2;

    dado1 = rand()%6 + 1;
    dado2 = rand()%6 + 1;

    if (debugMode) { //- - - - - - - - - - - - - - - - - - - - - - - debug
        cout << "DEBUG: il numero e' " << dado1 << " e " << dado2 << endl;
    }

    cout << "O-------------O" << endl;
    cout << "|   D A D I   |" << endl;
    cout << "O-------------O" << endl;
    cout << " " << endl;
    cout << "Inserisci il numero su cui vorresti scommettere (inserisci 40 per tornare al menu principale): ";
    cin >> scelta;

    if ((dado1 + dado2) == scelta) {
        cout << "Complimenti, hai vinto!" << endl;
        cout << "Verrai reindirizzato al menu dei dadi";
        wait();
        dadi();
    } else if (scelta == 40) {
        cout << "Verrai reindirizzato al menu principale";
        wait();
        menu();
    } else if ((scelta < 2) || (scelta > 12)) {
        cout << "ATTENZIONE: Inserire un numero accettabile";
        wait();
        dadi();
    } else {
        cout << "Peccato, hai perso!" << endl;
        cout << "Verrai reindirizzato al menu dei dadi";
        wait();
        dadi();
    }

}

void baccarat() { // - - - - - - - - - - - - - - - - - - - - - - - - meccanismi baccarat --  --  --  --  --  --  --  --  --  --  - COMPLETATO
    system("cls");
    srand(time(NULL));
    int scelta, contoPlayer, puntiPlayer=0, contoBanker, puntibanker=0;
    int player1, player2, player3;
    int banker1, banker2, banker3;
    int valori0[4] = {10, 11, 12, 13};

    player1 = rand()%14;
    player2 = rand()%14;
    player3 = rand()%14;
    banker1 = rand()%14;
    banker2 = rand()%14;
    banker3 = rand()%14;

    if (find(begin(valori0), end(valori0), player1) != end(valori0)) {
        player1 = 0;
    }
    if (find(begin(valori0), end(valori0), player2) != end(valori0)) {
        player2 = 0;
    }
    if (find(begin(valori0), end(valori0), player3) != end(valori0)) {
        player3 = 0;
    }
    if (find(begin(valori0), end(valori0), banker1) != end(valori0)) {
        banker1 = 0;
    }
    if (find(begin(valori0), end(valori0), banker2) != end(valori0)) {
        banker2 = 0;
    }
    if (find(begin(valori0), end(valori0), banker3) != end(valori0)) {
        banker3 = 0;
    }
    contoPlayer = player1 + player2;
    contoBanker = banker1 + banker2;

    if (contoPlayer > 10) {
        puntiPlayer = contoPlayer%10;
    } else if (contoPlayer <= 10) {
        puntiPlayer = contoPlayer;
    }
    if (contoBanker > 10) {
        puntibanker = contoBanker%10;
    } else if (contoBanker <= 10) {
        puntibanker = contoBanker;
    }

    if (debugMode) { //- - - - - - - - - - - - - - - - - - - - - - - debug
        cout << "DEBUG: i numeri sono: | Banchiere | giocatore |" << endl;
        cout << "                      |     " << banker1 << "     |     " << player1 << "     |" << endl;
        cout << "                      |     " << banker2 << "     |     " << player2 << "     |" << endl;
        cout << "                      |     " << banker3 << "     |     " << player3 << "     |" << endl;
    }

    cout << "O---------------------O" << endl;
    cout << "|   B A C C A R A T   |" << endl;
    cout << "O---------------------O" << endl;
    cout << " " << endl;
    cout << "Vorresti scommettere sul Giocatore o sul Banchiere?" << endl;
    cout << "- 1: Giocatore" << endl;
    cout << "- 2: Banchiere" << endl;
    cout << "- 0: Torna al menu principale" << endl;
    cout << "Scelta: ";
    cin >> scelta;
    if (scelta == 0) {
        cout << "Verrai reindirizzato al menu principale";
        wait();
        menu();
    } else {
        cout << " " << endl;
        cout << "                   Giocatore:   []  Banchiere:" << endl;
        cout << "                   O---O O---O  []  O---O O---O" << endl;
        cout << "Le carte sono:     | " << player1 << " | | " << player2 << " |  []  | " << banker1 << " | | " << banker2 << " |" << endl;
        cout << "                   O---O O---O  []  O---O O---O" << endl;
        cout << " " << endl;
        cout << "Il giocatore ha " << puntiPlayer << " punti." << endl;
        cout << "Il banchiere ha " << puntibanker << " punti." << endl;

        if (scelta == 0) {
            cout << "Verrai reindirizzato al menu principale";
            wait();
            menu();
        } else if (puntiPlayer == puntibanker) { //- - - - - - - - - - - - - - - - - - - - pareggio
            cout << "E' un pareggio, nessuno vince!" << endl;;
            system("pause");
            baccarat();
        } else if ((puntiPlayer >= 8) && (scelta == 1)) { // - - - - - - - - - - - - - - - player magg - vinto
            cout << "Il giocatore ha fatto un punteggio piu' alto, hai vinto!" << endl;
            system("pause");
            baccarat();
        } else if ((puntiPlayer >= 8) && (scelta == 2)) { // - - - - - - - - - - - - - - - player magg - perso
            cout << "Il giocatore ha fatto un punteggio piu' alto, hai perso!" << endl;
            system("pause");
            baccarat();
        } else if ((puntibanker >= 8) && (scelta == 1)) { // - - - - - - - - - - - - - - - banker magg - perso
            cout << "Il banchiere ha fatto un punteggio piu' alto, hai perso!" << endl;
            system("pause");
            baccarat();
        } else if ((puntibanker >= 8) && (scelta == 2)) { // - - - - - - - - - - - - - - - banker magg - vinto
            cout << "Il banchiere ha fatto un punteggio piu' alto, hai vinto!" << endl;
            system("pause");
            baccarat();
        } else if ((puntiPlayer >= 6) && (puntiPlayer > puntibanker) && (scelta == 1)) {// player stand - player magg - vinto
            cout << "Il giocatore ha fatto un punteggio piu' alto, hai vinto!" << endl;
            system("pause");
            baccarat();
        } else if ((puntiPlayer >= 6) && (puntiPlayer > puntibanker) && (scelta == 2)) {// player stand - player magg - perso
            cout << "Il giocatore ha faccio un punteggio più alto, hai perso!" << endl;
            system("pause");
            baccarat();
        } else if ((puntiPlayer >= 6) && (puntiPlayer < puntibanker) && (scelta == 1)) {// player stand - banker magg - perso
            cout << "Il banchiere ha fatto un punteggio più alto, hai perso!" << endl;
            system("pause");
            baccarat();
        } else if ((puntiPlayer >= 6) && (puntiPlayer < puntibanker) && (scelta == 2)) {// player stand - banker magg - vinto
            cout << "Il banchiere ha fatto un punteggio piu' alto, hai vinto!" << endl;
            system("pause");
            baccarat();
        } else if (puntiPlayer < 6) {//- - - - - - - - - - - - - - - - - - - - - - - - - - player pesca
            cout << "                                       O---O O---O O---O" << endl;
            cout << "Il giocatore pesca una nuova carta:    | " << player1 << " | | " << player2 << " | | " << player3 << " |" << endl;
            cout << "                                       O---O O---O O---O" << endl;
            cout << " " << endl;
            
            contoPlayer = player1 + player2 + player3;
            
            if (contoPlayer > 10) {
                puntiPlayer = contoPlayer%10;
            } else if (contoPlayer <= 10) {
                puntiPlayer = contoPlayer;
            }

            cout << "Il giocatore ha " << puntiPlayer << " punti." << endl;
            cout << "Il banchiere ha " << puntibanker << " punti." << endl;

            if (((player3 >= 9) || (player3 <= 1)) && (puntibanker >= 4)) { // - - - - - - banker stand
                if (puntiPlayer == puntibanker) { // - - - - - - - - - - - - - - - - - - - - - - - pareggio
                    cout << "E' un pareggio, nessuno vince!" << endl;
                    system("pause");
                    baccarat();
                } else if ((puntiPlayer > puntibanker) && (scelta == 1)) { //- - - - - - - - - - - player magg - vinto
                    cout << "Il giocatore ha fatto un punteggio maggiore, hai vinto!" << endl;
                    system("pause");
                    baccarat();
                } else if ((puntiPlayer > puntibanker) && (scelta == 2)) { // - - - - - - - player magg - perso
                    cout << "Il giocatore ha fatto un punteggio maggiore, hai perso!" << endl;
                    system("pause");
                    baccarat();
                } else if ((puntiPlayer < puntibanker) && (scelta == 1)) { // - - - - - - - player min -- perso
                    cout << "Il banchiere ha fatto un punteggio maggiore, hai perso!" << endl;
                    system("pause");
                    baccarat();
                } else if ((puntiPlayer < puntibanker) && (scelta == 2)) { // - - - - - - - player min -- vinto
                    cout << "Il banchiere ha fatto un punteggio maggiore, hai vinto!" << endl;
                    system("pause");
                    baccarat();
                }
            } else if (((player3 >= 9) || (player3 <= 1)) && (puntibanker < 4)) { // - - - banker pesca
                cout << "                                       O---O O---O O---O" << endl;
                cout << "Il banchiere pesca una nuova carta:    | " << banker1 << " | | " << banker2 << " | | " << banker3 << " |" << endl;
                cout << "                                       O---O O---O O---O" << endl;
                cout << " " << endl;
                
                contoBanker = banker1 + banker2 + banker3;
                
                if (contoBanker > 10) {
                    puntibanker = contoBanker%10;
                } else if (contoBanker <= 10) {
                    puntibanker = contoBanker;
                }

                cout << "Il giocatore ha " << puntiPlayer << " punti." << endl;
                cout << "Il banchiere ha " << puntibanker << " punti." << endl;

                if (puntiPlayer == puntibanker) { // - - - - - - - - - - - - - - - - - - - - - - - pareggio
                    cout << "E' un pareggio, nessuno vince!" << endl;
                    system("pause");
                    baccarat();
                } else if ((puntiPlayer > puntibanker) && (scelta == 1)) { //- - - - - - - - - - - player magg - vinto
                    cout << "Il giocatore ha fatto un punteggio maggiore, hai vinto!" << endl;
                    system("pause");
                    baccarat();
                } else if ((puntiPlayer > puntibanker) && (scelta == 2)) { // - - - - - - - player magg - perso
                    cout << "Il giocatore ha fatto un punteggio maggiore, hai perso!" << endl;
                    system("pause");
                    baccarat();
                } else if ((puntiPlayer < puntibanker) && (scelta == 1)) { // - - - - - - - player min -- perso
                    cout << "Il banchiere ha fatto un punteggio maggiore, hai perso!" << endl;
                    system("pause");
                    baccarat();
                } else if ((puntiPlayer < puntibanker) && (scelta == 2)) { // - - - - - - - player min -- vinto
                    cout << "Il banchiere ha fatto un punteggio maggiore, hai vinto!" << endl;
                    system("pause");
                    baccarat();
                }
            } else if ((player3 == 8) && (puntibanker >= 3)) { //- - - - - - - - - - - - - banker stand
                if (puntiPlayer == puntibanker) { // - - - - - - - - - - - - - - - - - - - - - - - pareggio
                    cout << "E' un pareggio, nessuno vince!" << endl;
                    system("pause");
                    baccarat();
                } else if ((puntiPlayer > puntibanker) && (scelta == 1)) { //- - - - - - - - - - - player magg - vinto
                    cout << "Il giocatore ha fatto un punteggio maggiore, hai vinto!" << endl;
                    system("pause");
                    baccarat();
                } else if ((puntiPlayer > puntibanker) && (scelta == 2)) { // - - - - - - - player magg - perso
                    cout << "Il giocatore ha fatto un punteggio maggiore, hai perso!" << endl;
                    system("pause");
                    baccarat();
                } else if ((puntiPlayer < puntibanker) && (scelta == 1)) { // - - - - - - - player min -- perso
                    cout << "Il banchiere ha fatto un punteggio maggiore, hai perso!" << endl;
                    system("pause");
                    baccarat();
                } else if ((puntiPlayer < puntibanker) && (scelta == 2)) { // - - - - - - - player min -- vinto
                    cout << "Il banchiere ha fatto un punteggio maggiore, hai vinto!" << endl;
                    system("pause");
                    baccarat();
                }
            } else if ((player3 == 8) && (puntibanker < 3)) { // - - - - - - - - - - - - - banker pesca
                cout << "                                       O---O O---O O---O" << endl;
                cout << "Il banchiere pesca una nuova carta:    | " << banker1 << " | | " << banker2 << " | | " << banker3 << " |" << endl;
                cout << "                                       O---O O---O O---O" << endl;
                cout << " " << endl;
                
                contoBanker = banker1 + banker2 + banker3;
                
                if (contoBanker > 10) {
                    puntibanker = contoBanker%10;
                } else if (contoBanker <= 10) {
                    puntibanker = contoBanker;
                }

                cout << "Il giocatore ha " << puntiPlayer << " punti." << endl;
                cout << "Il banchiere ha " << puntibanker << " punti." << endl;

                if (puntiPlayer == puntibanker) { // - - - - - - - - - - - - - - - - - - - - - - - pareggio
                    cout << "E' un pareggio, nessuno vince!" << endl;
                    system("pause");
                    baccarat();
                } else if ((puntiPlayer > puntibanker) && (scelta == 1)) { //- - - - - - - - - - - player magg - vinto
                    cout << "Il giocatore ha fatto un punteggio maggiore, hai vinto!" << endl;
                    system("pause");
                    baccarat();
                } else if ((puntiPlayer > puntibanker) && (scelta == 2)) { // - - - - - - - player magg - perso
                    cout << "Il giocatore ha fatto un punteggio maggiore, hai perso!" << endl;
                    system("pause");
                    baccarat();
                } else if ((puntiPlayer < puntibanker) && (scelta == 1)) { // - - - - - - - player min -- perso
                    cout << "Il banchiere ha fatto un punteggio maggiore, hai perso!" << endl;
                    system("pause");
                    baccarat();
                } else if ((puntiPlayer < puntibanker) && (scelta == 2)) { // - - - - - - - player min -- vinto
                    cout << "Il banchiere ha fatto un punteggio maggiore, hai vinto!" << endl;
                    system("pause");
                    baccarat();
                }
            } else if (((player3 == 6) || (player3 == 7)) && (puntibanker == 7)) { //- - - banker stand
                if (puntiPlayer == puntibanker) { // - - - - - - - - - - - - - - - - - - - - - - - pareggio
                    cout << "E' un pareggio, nessuno vince!" << endl;
                    system("pause");
                    baccarat();
                } else if ((puntiPlayer > puntibanker) && (scelta == 1)) { //- - - - - - - - - - - player magg - vinto
                    cout << "Il giocatore ha fatto un punteggio maggiore, hai vinto!" << endl;
                    system("pause");
                    baccarat();
                } else if ((puntiPlayer > puntibanker) && (scelta == 2)) { // - - - - - - - player magg - perso
                    cout << "Il giocatore ha fatto un punteggio maggiore, hai perso!" << endl;
                    system("pause");
                    baccarat();
                } else if ((puntiPlayer < puntibanker) && (scelta == 1)) { // - - - - - - - player min -- perso
                    cout << "Il banchiere ha fatto un punteggio maggiore, hai perso!" << endl;
                    system("pause");
                    baccarat();
                } else if ((puntiPlayer < puntibanker) && (scelta == 2)) { // - - - - - - - player min -- vinto
                    cout << "Il banchiere ha fatto un punteggio maggiore, hai vinto!" << endl;
                    system("pause");
                    baccarat();
                }
            } else if (((player3 == 6) || (player3 == 7)) && (puntibanker < 7)) { // - - - banker pesca
                cout << "                                       O---O O---O O---O" << endl;
                cout << "Il banchiere pesca una nuova carta:    | " << banker1 << " | | " << banker2 << " | | " << banker3 << " |" << endl;
                cout << "                                       O---O O---O O---O" << endl;
                cout << " " << endl;
                
                contoBanker = banker1 + banker2 + banker3;
                
                if (contoBanker > 10) {
                    puntibanker = contoBanker%10;
                } else if (contoBanker <= 10) {
                    puntibanker = contoBanker;
                }

                cout << "Il giocatore ha " << puntiPlayer << " punti." << endl;
                cout << "Il banchiere ha " << puntibanker << " punti." << endl;

                if (puntiPlayer == puntibanker) { // - - - - - - - - - - - - - - - - - - - - - - - pareggio
                    cout << "E' un pareggio, nessuno vince!" << endl;
                    system("pause");
                    baccarat();
                } else if ((puntiPlayer > puntibanker) && (scelta == 1)) { //- - - - - - - - - - - player magg - vinto
                    cout << "Il giocatore ha fatto un punteggio maggiore, hai vinto!" << endl;
                    system("pause");
                    baccarat();
                } else if ((puntiPlayer > puntibanker) && (scelta == 2)) { // - - - - - - - player magg - perso
                    cout << "Il giocatore ha fatto un punteggio maggiore, hai perso!" << endl;
                    system("pause");
                    baccarat();
                } else if ((puntiPlayer < puntibanker) && (scelta == 1)) { // - - - - - - - player min -- perso
                    cout << "Il banchiere ha fatto un punteggio maggiore, hai perso!" << endl;
                    system("pause");
                    baccarat();
                } else if ((puntiPlayer < puntibanker) && (scelta == 2)) { // - - - - - - - player min -- vinto
                    cout << "Il banchiere ha fatto un punteggio maggiore, hai vinto!" << endl;
                    system("pause");
                    baccarat();
                }
            } else if (((player3 == 4) || (player3 == 5)) && (puntibanker >= 6)) { //- - - banker stand
                if (puntiPlayer == puntibanker) { // - - - - - - - - - - - - - - - - - - - - - - - pareggio
                    cout << "E' un pareggio, nessuno vince!" << endl;
                    system("pause");
                    baccarat();
                } else if ((puntiPlayer > puntibanker) && (scelta == 1)) { //- - - - - - - - - - - player magg - vinto
                    cout << "Il giocatore ha fatto un punteggio maggiore, hai vinto!" << endl;
                    system("pause");
                    baccarat();
                } else if ((puntiPlayer > puntibanker) && (scelta == 2)) { // - - - - - - - player magg - perso
                    cout << "Il giocatore ha fatto un punteggio maggiore, hai perso!" << endl;
                    system("pause");
                    baccarat();
                } else if ((puntiPlayer < puntibanker) && (scelta == 1)) { // - - - - - - - player min -- perso
                    cout << "Il banchiere ha fatto un punteggio maggiore, hai perso!" << endl;
                    system("pause");
                    baccarat();
                } else if ((puntiPlayer < puntibanker) && (scelta == 2)) { // - - - - - - - player min -- vinto
                    cout << "Il banchiere ha fatto un punteggio maggiore, hai vinto!" << endl;
                    system("pause");
                    baccarat();
                }
            } else if (((player3 == 4) || (player3 == 5)) && (puntibanker < 6)) { // - - - banker pesca
                cout << "                                       O---O O---O O---O" << endl;
                cout << "Il banchiere pesca una nuova carta:    | " << banker1 << " | | " << banker2 << " | | " << banker3 << " |" << endl;
                cout << "                                       O---O O---O O---O" << endl;
                cout << " " << endl;
                
                contoBanker = banker1 + banker2 + banker3;
                
                if (contoBanker > 10) {
                    puntibanker = contoBanker%10;
                } else if (contoBanker <= 10) {
                    puntibanker = contoBanker;
                }

                cout << "Il giocatore ha " << puntiPlayer << " punti." << endl;
                cout << "Il banchiere ha " << puntibanker << " punti." << endl;

                if (puntiPlayer == puntibanker) { // - - - - - - - - - - - - - - - - - - - - - - - pareggio
                    cout << "E' un pareggio, nessuno vince!" << endl;
                    system("pause");
                    baccarat();
                } else if ((puntiPlayer > puntibanker) && (scelta == 1)) { //- - - - - - - - - - - player magg - vinto
                    cout << "Il giocatore ha fatto un punteggio maggiore, hai vinto!" << endl;
                    system("pause");
                    baccarat();
                } else if ((puntiPlayer > puntibanker) && (scelta == 2)) { // - - - - - - - player magg - perso
                    cout << "Il giocatore ha fatto un punteggio maggiore, hai perso!" << endl;
                    system("pause");
                    baccarat();
                } else if ((puntiPlayer < puntibanker) && (scelta == 1)) { // - - - - - - - player min -- perso
                    cout << "Il banchiere ha fatto un punteggio maggiore, hai perso!" << endl;
                    system("pause");
                    baccarat();
                } else if ((puntiPlayer < puntibanker) && (scelta == 2)) { // - - - - - - - player min -- vinto
                    cout << "Il banchiere ha fatto un punteggio maggiore, hai vinto!" << endl;
                    system("pause");
                    baccarat();
                }
            } else if (((player3 == 2) || (player3 == 3)) && (puntibanker >= 5)) { //- - - banker stand
                if (puntiPlayer == puntibanker) { // - - - - - - - - - - - - - - - - - - - - - - - pareggio
                    cout << "E' un pareggio, nessuno vince!" << endl;
                    system("pause");
                    baccarat();
                } else if ((puntiPlayer > puntibanker) && (scelta == 1)) { //- - - - - - - - - - - player magg - vinto
                    cout << "Il giocatore ha fatto un punteggio maggiore, hai vinto!" << endl;
                    system("pause");
                    baccarat();
                } else if ((puntiPlayer > puntibanker) && (scelta == 2)) { // - - - - - - - player magg - perso
                    cout << "Il giocatore ha fatto un punteggio maggiore, hai perso!" << endl;
                    system("pause");
                    baccarat();
                } else if ((puntiPlayer < puntibanker) && (scelta == 1)) { // - - - - - - - player min -- perso
                    cout << "Il banchiere ha fatto un punteggio maggiore, hai perso!" << endl;
                    system("pause");
                    baccarat();
                } else if ((puntiPlayer < puntibanker) && (scelta == 2)) { // - - - - - - - player min -- vinto
                    cout << "Il banchiere ha fatto un punteggio maggiore, hai vinto!" << endl;
                    system("pause");
                    baccarat();
                }
            } else if (((player3 == 2) || (player3 == 3)) && (puntibanker < 5)) { // - - - banker pesca
                cout << "                                       O---O O---O O---O" << endl;
                cout << "Il banchiere pesca una nuova carta:    | " << banker1 << " | | " << banker2 << " | | " << banker3 << " |" << endl;
                cout << "                                       O---O O---O O---O" << endl;
                cout << " " << endl;
                
                contoBanker = banker1 + banker2 + banker3;
                
                if (contoBanker > 10) {
                    puntibanker = contoBanker%10;
                } else if (contoBanker <= 10) {
                    puntibanker = contoBanker;
                }

                cout << "Il giocatore ha " << puntiPlayer << " punti." << endl;
                cout << "Il banchiere ha " << puntibanker << " punti." << endl;

                if (puntiPlayer == puntibanker) { // - - - - - - - - - - - - - - - - - - - - - - - pareggio
                    cout << "E' un pareggio, nessuno vince!" << endl;
                    system("pause");
                    baccarat();
                } else if ((puntiPlayer > puntibanker) && (scelta == 1)) { //- - - - - - - - - - - player magg - vinto
                    cout << "Il giocatore ha fatto un punteggio maggiore, hai vinto!" << endl;
                    system("pause");
                    baccarat();
                } else if ((puntiPlayer > puntibanker) && (scelta == 2)) { // - - - - - - - player magg - perso
                    cout << "Il giocatore ha fatto un punteggio maggiore, hai perso!" << endl;
                    system("pause");
                    baccarat();
                } else if ((puntiPlayer < puntibanker) && (scelta == 1)) { // - - - - - - - player min -- perso
                    cout << "Il banchiere ha fatto un punteggio maggiore, hai perso!" << endl;
                    system("pause");
                    baccarat();
                } else if ((puntiPlayer < puntibanker) && (scelta == 2)) { // - - - - - - - player min -- vinto
                    cout << "Il banchiere ha fatto un punteggio maggiore, hai vinto!" << endl;
                    system("pause");
                    baccarat();
                }
            }
        } else { //- - - - - - - - - - - - - - - - - - - - - - - - - - - bro scrive una coglionata
            cout << "ATTENZIONE: Inserire un opzione accettabile";
            wait();
            baccarat();
        }
    }
}

void blackjack() { //- - - - - - - - - - - - - - - - - - - - - - - - meccanismi blackjack --  --  -- --  --  --  --  --  --  --  - COMPLETATO
    srand(time(NULL));
    system("cls");

    int player1, player2, player3;
    int dealer1, dealer2, dealer3, dealer4, dealer5, dealer6;
    int scelta, contoPlayer=0, contoDealer=0;

    player1 = (rand()%13 + 1), dealer1 = (rand()%13 + 1);
    player2 = (rand()%13 + 1), dealer2 = (rand()%13 + 1);
    player3 = (rand()%13 + 1), dealer3 = (rand()%13 + 1);
    dealer4 = (rand()%13 + 1);
    dealer5 = (rand()%13 + 1);
    dealer6 = (rand()%13 + 1);

    if (player1 > 10) player1 = 10; if (dealer1 > 10) dealer1 = 10;
    if (player2 > 10) player2 = 10; if (dealer2 > 10) dealer2 = 10;
    if (player3 > 10) player3 = 10; if (dealer3 > 10) dealer3 = 10;
    if (dealer4 > 10) dealer4 = 10;
    if (dealer5 > 10) dealer5 = 10;
    if (dealer6 > 10) dealer6 = 10;

    contoPlayer = player1 + player2;
    contoDealer = dealer1 + dealer2;

    if (debugMode) { //- - - - - - - - - - - - - - - - - - - - - - - debug
        cout << "DEBUG: i numeri sono: | Mazziere | giocatore |" << endl;
        cout << "                      |    " << dealer1 << "     |     " << player1 << "     |" << endl;
        cout << "                      |    " << dealer2 << "     |     " << player2 << "     |" << endl;
        cout << "                      |    " << dealer3 << "     |     " << player3 << "     |" << endl;
        cout << "                      |    " << dealer4 << "     |" << endl;
        cout << "                      |    " << dealer5 << "     |" << endl;
        cout << "                      |    " << dealer6 << "     |" << endl;
    }

    cout << "O-----------------------O" << endl;
    cout << "|   B L A C K J A C K   |" << endl;
    cout << "O-----------------------O" << endl;
    cout << " " << endl;
    cout << "                               O---O O---O" << endl;
    cout << "le carte del mazziere sono:    | " << dealer1 << " | | ? |" << endl;
    cout << "                               O---O O---O" << endl << endl;
    cout << "                               O---O O---O" << endl;
    cout << "Le carte del giocatore sono:   | " << player1 << " | | " << player2 << " |" << endl;
    cout << "                               O---O O---O" << endl;
    cout << " " << endl;
    cout << "Viste le carte, cosa vorresti fare?" << endl;
    cout << "- 1: Stand" << endl;
    cout << "- 2: Pesca" << endl;
    cout << "- 0: Torna al menu principale" << endl;
    cout << "Scelta: ";
    cin >> scelta;

    if (contoPlayer > 21) {
        cout << "Il giocatore ha sballato; hai perso!" << endl;
        system("pause");
        blackjack();
    } else if (contoDealer > 21) {
        cout << "Il dealer ha sballato; hai vinto!" << endl;
        system("pause");
        blackjack();
    }

    switch (scelta) {
    case 1: // --  --  --  --  COMPLETATO
        cout << "                               O---O O---O" << endl;
        cout << "Le carte del mazziere sono:    | " << dealer1 << " | | " << dealer2 << " |" << endl;
        cout << "                               O---O O---O" << endl;
        cout << " " << endl;

        if (contoDealer < 16) { // <16 con 2 carte, pesca
            cout << "Il dealer pesca una carta";
            wait();
            cout << endl;
            cout << "                                   O---O O---O O---O" << endl;
            cout << "Le carte del mazziere ora sono:    | " << dealer1 << " | | " << dealer2 << " | | " << dealer3 << " |" << endl;
            cout << "                                   O---O O---O O---O" << endl;
            cout << " " << endl;
            contoDealer = dealer1 + dealer2 + dealer3;

            if (contoDealer < 16) { // <16 con 3 carte, pesca
                cout << "Il dealer pesca una carta";
                wait();
                cout << endl;
                cout << "                                   O---O O---O O---O O---O" << endl;
                cout << "Le carte del mazziere ora sono:    | " << dealer1 << " | | " << dealer2 << " | | " << dealer3 << " | | " << dealer4 << " |" << endl;
                cout << "                                   O---O O---O O---O O---O" << endl;
                cout << " " << endl;
                contoDealer = dealer1 + dealer2 + dealer3 + dealer4;

                if (contoDealer < 16) { // 16 con 4 carte, pesca
                    cout << "Il dealer pesca una carta";
                    wait();
                    cout << endl;
                    cout << "                                   O---O O---O O---O O---O O---O" << endl;
                    cout << "Le carte del mazziere ora sono:    | " << dealer1 << " | | " << dealer2 << " | | " << dealer3 << " | | " << dealer4 << " | | " << dealer5 << " |" << endl;
                    cout << "                                   O---O O---O O---O O---O O---O" << endl;
                    cout << " " << endl;
                    contoDealer = dealer1 + dealer2 + dealer3 + dealer4 + dealer5;

                    if (contoDealer < 16) { // <16 con 5 carte, pesca
                        cout << "Il dealer pesca una carta";
                        wait();
                        cout << endl;
                        cout << "                                   O---O O---O O---O O---O O---O O---O" << endl;
                        cout << "Le carte del mazziere ora sono:    | " << dealer1 << " | | " << dealer2 << " | | " << dealer3 << " | | " << dealer4 << " | | " << dealer5 << " | | " << dealer6 << " |" << endl;
                        cout << "                                   O---O O---O O---O O---O O---O O---O" << endl;
                        cout << " " << endl;
                        contoDealer = dealer1 + dealer2 + dealer3 + dealer4 + dealer5 + dealer6;

                        if (contoDealer > 21) {
                            cout << "Il dealse ha sballato; hai vinto!" << endl;
                            system("pause");
                            blackjack();
                            break;
                        } else if (contoDealer < contoPlayer) {
                            cout << "Il giocatore ha fatto " << contoPlayer << ", mentre il dealer ha fatto " << contoDealer << "; hai vinto!" << endl;
                            system("pause");
                            blackjack();
                            break;
                        } else if (contoDealer > contoPlayer) {
                            cout << "Il giocatore ha fatto " << contoPlayer << ", mentre il dealer ha fatto " << contoDealer << "; hai perso!" << endl;
                            system("pause");
                            blackjack();
                            break;
                        } else {
                            cout << "Il giocatore ha fatto " << contoPlayer << ", e il dealer ha fatto " << contoDealer << "; e' un pareggio!" << endl;
                            system("pause");
                            blackjack();
                            break;
                        }
                        
                    } else { // >16 con 5 carte, stand
                        if (contoDealer > 21) {
                            cout << "Il mazziere ha sballati; hai vinto!" << endl;
                            system("pause");
                            blackjack();
                            break;
                        } else if (contoDealer < contoPlayer) {
                            cout << "Il giocatore ha fatto " << contoPlayer << ", mentre il dealer ha fatto " << contoDealer << "; hai vinto!" << endl;
                            system("pause");
                            blackjack();
                            break;
                        } else if (contoDealer > contoPlayer) {
                            cout << "Il giocatore ha fatto " << contoPlayer << ", mentre il dealer ha fatto " << contoDealer << "; hai perso!" << endl;
                            system("pause");
                            blackjack();
                            break;
                        } else {
                            cout << "Il giocatore ha fatto " << contoPlayer << ", e il dealer ha fatto " << contoDealer << "; e' un pareggio!" << endl;
                            system("pause");
                            blackjack();
                            break;
                        }
                    }
                    if (contoDealer < contoPlayer) {
                        cout << "Il giocatore ha fatto " << contoPlayer << ", mentre il dealer ha fatto " << contoDealer << "; hai vinto!" << endl;
                        system("pause");
                        blackjack();
                        break;
                    } else if (contoDealer > contoPlayer) {
                        cout << "Il giocatore ha fatto " << contoPlayer << ", mentre il dealer ha fatto " << contoDealer << "; hai perso!" << endl;
                        system("pause");
                        blackjack();
                        break;
                    } else {
                        cout << "Il giocatore ha fatto " << contoPlayer << ", e il dealer ha fatto " << contoDealer << "; e' un pareggio!" << endl;
                        system("pause");
                        blackjack();
                        break;
                    }
                } else { // >16 con 4 carte, stand

                    if (contoDealer > 21) {
                        cout << "Il dealer ha sballato; hai vinto!" << endl;
                        system("pause");
                        blackjack();
                        break;
                    } else if (contoDealer < contoPlayer) {
                        cout << "Il giocatore ha fatto " << contoPlayer << ", mentre il dealer ha fatto " << contoDealer << "; hai vinto!" << endl;
                        system("pause");
                        blackjack();
                        break;
                    } else if (contoDealer > contoPlayer) {
                        cout << "Il giocatore ha fatto " << contoPlayer << ", mentre il dealer ha fatto " << contoDealer << "; hai perso!" << endl;
                        system("pause");
                        blackjack();
                        break;
                    } else {
                        cout << "Il giocatore ha fatto " << contoPlayer << ", e il dealer ha fatto " << contoDealer << "; e' un pareggio!" << endl;
                        system("pause");
                        blackjack();
                        break;
                    }
                }

                if (contoDealer < contoPlayer) {
                    cout << "Il giocatore ha fatto " << contoPlayer << ", mentre il dealer ha fatto " << contoDealer << "; hai vinto!" << endl;
                    system("pause");
                    blackjack();
                    break;
                } else if (contoDealer > contoPlayer) {
                    cout << "Il giocatore ha fatto " << contoPlayer << ", mentre il dealer ha fatto " << contoDealer << "; hai perso!" << endl;
                    system("pause");
                    blackjack();
                    break;
                } else {
                    cout << "Il giocatore ha fatto " << contoPlayer << ", e il dealer ha fatto " << contoDealer << "; e' un pareggio!" << endl;
                    system("pause");
                    blackjack();
                    break;
                }
            } else { // >16 con 3 carte, stand
                if (contoDealer > 21) {
                    cout << "Il dealer ha sballato; hai vinto!" << endl;
                    system("pause");
                    blackjack();
                    break;
                } else if (contoDealer < contoPlayer) {
                    cout << "Il giocatore ha fatto " << contoPlayer << ", mentre il dealer ha fatto " << contoDealer << "; hai vinto!" << endl;
                    system("pause");
                    blackjack();
                    break;
                } else if (contoDealer > contoPlayer) {
                    cout << "Il giocatore ha fatto " << contoPlayer << ", mentre il dealer ha fatto " << contoDealer << "; hai perso!" << endl;
                    system("pause");
                    blackjack();
                    break;
                } else {
                    cout << "Il giocatore ha fatto " << contoPlayer << ", e il dealer ha fatto " << contoDealer << "; e' un pareggio!" << endl;
                    system("pause");
                    blackjack();
                    break;
                }
            }
        } else { // >16 con 2 carte, stand
            if (contoDealer > 21) {
                cout << "Il dealer ha sballato; hai vinto!" << endl;
                system("pause");
                blackjack();
                break;
            } else if (contoDealer < contoPlayer) {
                cout << "Il giocatore ha fatto " << contoPlayer << ", mentre il dealer ha fatto " << contoDealer << "; hai vinto!" << endl;
                system("pause");
                blackjack();
                break;
            } else if (contoDealer > contoPlayer) {
                cout << "Il giocatore ha fatto " << contoPlayer << ", mentre il dealer ha fatto " << contoDealer << "; hai perso!" << endl;
                system("pause");
                blackjack();
                break;
            } else {
                cout << "Il giocatore ha fatto " << contoPlayer << ", e il dealer ha fatto " << contoDealer << "; e' un pareggio!" << endl;
                system("pause");
                blackjack();
                break;
            }
        }
        break;
    case 2:
        cout << "                               O---O O---O" << endl;
        cout << "Le carte del mazziere sono:    | " << dealer1 << " | | " << dealer2 << " |" << endl;
        cout << "                               O---O O---O" << endl;
        cout << " " << endl;
        cout << "                               O---O O---O O---O" << endl;
        cout << "Le tue carte ora sono:         | " << player1 << " | | " << player2 << " | | " << player3 << " |" << endl;
        cout << "                               O---O O---O O---O" << endl;
        cout << " " << endl;

        contoPlayer = player1 + player2 + player3;

        if (contoPlayer > 21) {
            cout << "Il giocatore ha sballato; hai perso!" << endl;
            system("pause");
            blackjack();
            break;
        } else if (contoDealer > 21) {
            cout << "Il dealer ha sballato; hai vinto!" << endl;
            system("pause");
            blackjack();
            break;
        } else if (contoPlayer == 21) {
            cout << "Il giocatore ha fatto Blackjack; hai vinto!" << endl;
            system("pause");
            blackjack();
            break;
        }

        if (contoDealer < 16) { // <16 con 2 carte, pesca
            cout << "Il dealer pesca una carta";
            wait();
            cout << endl;
            cout << "                                   O---O O---O O---O" << endl;
            cout << "Le carte del mazziere ora sono:    | " << dealer1 << " | | " << dealer2 << " | | " << dealer3 << " |" << endl;
            cout << "                                   O---O O---O O---O" << endl;
            cout << " " << endl;
            contoDealer = dealer1 + dealer2 + dealer3;

            if (contoDealer < 16) { // <16 con 3 carte, pesca
                cout << "Il dealer pesca una carta";
                wait();
                cout << endl;
                cout << "                                   O---O O---O O---O O---O" << endl;
                cout << "Le carte del mazziere ora sono:    | " << dealer1 << " | | " << dealer2 << " | | " << dealer3 << " | | " << dealer4 << " |" << endl;
                cout << "                                   O---O O---O O---O O---O" << endl;
                cout << " " << endl;
                contoDealer = dealer1 + dealer2 + dealer3 + dealer4;

                if (contoDealer < 16) { // 16 con 4 carte, pesca
                    cout << "Il dealer pesca una carta";
                    wait();
                    cout << endl;
                    cout << "                                   O---O O---O O---O O---O O---O" << endl;
                    cout << "Le carte del mazziere ora sono:    | " << dealer1 << " | | " << dealer2 << " | | " << dealer3 << " | | " << dealer4 << " | | " << dealer5 << " |" << endl;
                    cout << "                                   O---O O---O O---O O---O O---O" << endl;
                    cout << " " << endl;
                    contoDealer = dealer1 + dealer2 + dealer3 + dealer4 + dealer5;

                    if (contoDealer < 16) { // <16 con 5 carte, pesca
                        cout << "Il dealer pesca una carta";
                        wait();
                        cout << endl;
                        cout << "                                   O---O O---O O---O O---O O---O O---O" << endl;
                        cout << "Le carte del mazziere ora sono:    | " << dealer1 << " | | " << dealer2 << " | | " << dealer3 << " | | " << dealer4 << " | | " << dealer5 << " | | " << dealer6 << " |" << endl;
                        cout << "                                   O---O O---O O---O O---O O---O O---O" << endl;
                        cout << " " << endl;
                        contoDealer = dealer1 + dealer2 + dealer3 + dealer4 + dealer5 + dealer6;

                        if (contoDealer > 21) {
                            cout << "Il dealer ha sballato; hai vinto!" << endl;
                            system("pause");
                            blackjack();
                            break;
                        } else if (contoDealer < contoPlayer) {
                            cout << "Il giocatore ha fatto " << contoPlayer << ", mentre il dealer ha fatto " << contoDealer << "; hai vinto!" << endl;
                            system("pause");
                            blackjack();
                            break;
                        } else if (contoDealer > contoPlayer) {
                            cout << "Il giocatore ha fatto " << contoPlayer << ", mentre il dealer ha fatto " << contoDealer << "; hai perso!" << endl;
                            system("pause");
                            blackjack();
                            break;
                        } else {
                            cout << "Il giocatore ha fatto " << contoPlayer << ", e il dealer ha fatto " << contoDealer << "; e' un pareggio!" << endl;
                            system("pause");
                            blackjack();
                            break;
                        }
                        
                    } else { // >16 con 5 carte, stand
                        if (contoDealer > 21) {
                            cout << "Il mazziere ha sballato; hai vinto!" << endl;
                            system("pause");
                            blackjack();
                            break;
                        } else if (contoDealer < contoPlayer) {
                            cout << "Il giocatore ha fatto " << contoPlayer << ", mentre il dealer ha fatto " << contoDealer << "; hai vinto!" << endl;
                            system("pause");
                            blackjack();
                            break;
                        } else if (contoDealer > contoPlayer) {
                            cout << "Il giocatore ha fatto " << contoPlayer << ", mentre il dealer ha fatto " << contoDealer << "; hai perso!" << endl;
                            system("pause");
                            blackjack();
                            break;
                        } else {
                            cout << "Il giocatore ha fatto " << contoPlayer << ", e il dealer ha fatto " << contoDealer << "; e' un pareggio!" << endl;
                            system("pause");
                            blackjack();
                            break;
                        }
                    }
                    if (contoDealer < contoPlayer) {
                        cout << "Il giocatore ha fatto " << contoPlayer << ", mentre il dealer ha fatto " << contoDealer << "; hai vinto!" << endl;
                        system("pause");
                        blackjack();
                        break;
                    } else if (contoDealer > contoPlayer) {
                        cout << "Il giocatore ha fatto " << contoPlayer << ", mentre il dealer ha fatto " << contoDealer << "; hai perso!" << endl;
                        system("pause");
                        blackjack();
                        break;
                    } else {
                        cout << "Il giocatore ha fatto " << contoPlayer << ", e il dealer ha fatto " << contoDealer << "; e' un pareggio!" << endl;
                        system("pause");
                        blackjack();
                        break;
                    }
                } else { // >16 con 4 carte, stand

                    if (contoDealer > 21) {
                        cout << "Il dealer ha sballato; hai vinto!" << endl;
                        system("pause");
                        blackjack();
                        break;
                    } else if (contoDealer < contoPlayer) {
                        cout << "Il giocatore ha fatto " << contoPlayer << ", mentre il dealer ha fatto " << contoDealer << "; hai vinto!" << endl;
                        system("pause");
                        blackjack();
                        break;
                    } else if (contoDealer > contoPlayer) {
                        cout << "Il giocatore ha fatto " << contoPlayer << ", mentre il dealer ha fatto " << contoDealer << "; hai perso!" << endl;
                        system("pause");
                        blackjack();
                        break;
                    } else {
                        cout << "Il giocatore ha fatto " << contoPlayer << ", e il dealer ha fatto " << contoDealer << "; e' un pareggio!" << endl;
                        system("pause");
                        blackjack();
                        break;
                    }
                }

                if (contoDealer < contoPlayer) {
                    cout << "Il giocatore ha fatto " << contoPlayer << ", mentre il dealer ha fatto " << contoDealer << "; hai vinto!" << endl;
                    system("pause");
                    blackjack();
                    break;
                } else if (contoDealer > contoPlayer) {
                    cout << "Il giocatore ha fatto " << contoPlayer << ", mentre il dealer ha fatto " << contoDealer << "; hai perso!" << endl;
                    system("pause");
                    blackjack();
                    break;
                } else {
                    cout << "Il giocatore ha fatto " << contoPlayer << ", e il dealer ha fatto " << contoDealer << "; e' un pareggio!" << endl;
                    system("pause");
                    blackjack();
                    break;
                }
            } else { // >16 con 3 carte, stand
                if (contoDealer > 21) {
                    cout << "Il dealer ha sballato; hai vinto!" << endl;
                    system("pause");
                    blackjack();
                    break;
                } else if (contoDealer < contoPlayer) {
                    cout << "Il giocatore ha fatto " << contoPlayer << ", mentre il dealer ha fatto " << contoDealer << "; hai vinto!" << endl;
                    system("pause");
                    blackjack();
                    break;
                } else if (contoDealer > contoPlayer) {
                    cout << "Il giocatore ha fatto " << contoPlayer << ", mentre il dealer ha fatto " << contoDealer << "; hai perso!" << endl;
                    system("pause");
                    blackjack();
                    break;
                } else {
                    cout << "Il giocatore ha fatto " << contoPlayer << ", e il dealer ha fatto " << contoDealer << "; e' un pareggio!" << endl;
                    system("pause");
                    blackjack();
                    break;
                }
            }
        } else { // >16 con 2 carte, stand
            if (contoDealer > 21) {
                cout << "Il dealer ha sballato; hai vinto!" << endl;
                system("pause");
                blackjack();
                break;
            } else if (contoDealer < contoPlayer) {
                cout << "Il giocatore ha fatto " << contoPlayer << ", mentre il dealer ha fatto " << contoDealer << "; hai vinto!" << endl;
                system("pause");
                blackjack();
                break;
            } else if (contoDealer > contoPlayer) {
                cout << "Il giocatore ha fatto " << contoPlayer << ", mentre il dealer ha fatto " << contoDealer << "; hai perso!" << endl;
                system("pause");
                blackjack();
                break;
            } else {
                cout << "Il giocatore ha fatto " << contoPlayer << ", e il dealer ha fatto " << contoDealer << "; e' un pareggio!" << endl;
                system("pause");
                blackjack();
                break;
            }
        }
    case 0:
        cout << "Verrai reindirizzato al menu principale";
        wait();
        menu();
        break;
    default:
        cout << "ATTENZIONE: Selezionare un opzione accettabile";
        wait();
        blackjack();
        break;
    }
}

void sassoCartaForbici() {// - - - - - - - - - - - - - - - - - - - - meccanismi Sasso-Carta-forbici  --  --  --  --  --  --  --  - COMPLETATO
    srand(time(NULL));
    system("cls");
    int scelta, mossa;

    mossa = rand()%3;
    /*  Mossa == 0  >  Sasso
        Mossa == 1  >  Carta
        Mossa == 2  >  Forbici  */

    if (debugMode) {
        cout << "DEBUG: la casa ha scelto: " << mossa << endl;
    }

    cout << "O-----------------------------------------------O" << endl;
    cout << "|   S A S S O  -  C A R T A  -  F O R B I C I   |" << endl;
    cout << "O-----------------------------------------------O" << endl;
    cout << " " << endl;
    cout << "Scegli Sasso, Carta o Forbici?" << endl;
    cout << "- 1: Sasso" << endl;
    cout << "- 2: Carta" << endl;
    cout << "- 3: Forbici" << endl;
    cout << "- 0: Torna al menu principale" << endl;
    cout << "Scelta: ";
    cin >> scelta;
    cout << " " << endl;

    switch (scelta) {
        case 1:
            if (mossa == 0) {
                cout << "La casa ha scelto Sasso, e' un pareggio!" << endl;
                system("pause");
                sassoCartaForbici();
                break;
            } else if (mossa == 1) {
                cout << "La casa sceglie Carta, hai perso!" << endl;
                system("pause");
                sassoCartaForbici();
                break;
            } else if (mossa == 2) {
                cout << "La casa ha scelto Forbici, hai vinto!" << endl;
                system("pause");
                sassoCartaForbici();
                break;
            }
            break;
        case 2:
            if (mossa == 0) {
                cout << "La casa ha scelto Sasso, hai perso!" << endl;
                system("pause");
                sassoCartaForbici();
                break;
            } else if (mossa == 1) {
                cout << "La casa sceglie Carta, e' un pareggio!" << endl;
                system("pause");
                sassoCartaForbici();
                break;
            } else if (mossa == 2) {
                cout << "La casa ha scelto Forbici, hai perso!" << endl;
                system("pause");
                sassoCartaForbici();
                break;
            }
            break;
        case 3:
            if (mossa == 0) {
                cout << "Anche la casa ha scelta il Sasso; hai perso!" << endl;
                system("pause");
                sassoCartaForbici();
                break;
            } else if (mossa == 1) {
                cout << "La casa sceglie Carta, hai vinto!" << endl;
                system("pause");
                sassoCartaForbici();
                break;
            } else if (mossa == 2) {
                cout << "La casa ha scelto Forbici, e' un pareggio!" << endl;
                system("pause");
                sassoCartaForbici();
                break;
            }
            break;
        case 0:
            cout << "Verrai reindirizzato al menu principale";
            wait();
            menu();
            break;
        default:
            cout << "ATTENZIONE: Inserire un valore accettabile";
            wait();
            sassoCartaForbici();
            break;
    }
}

void arrivederci() {// - - - - - - - - - - - - - - - - - - - - - - - arrivederci --  --  --  --  --  --  --  --  --  --  --  --  - COMPLETATO
    system("cls");
    int scelta;

    cout << "O---------------------------O" << endl;
    cout << "|   A R R I V E D E R C I   |" << endl;
    cout << "O---------------------------O" << endl;
    cout << " " << endl;
    cout << "Sei sicuro di voler uscire? Qui ci sono molte cose divertenti da fare!" << endl;
    cout << "- 1: Voglio non abbandonare la presenza di questo programma" << endl; //   rimane
    cout << "- 2: Non voglio non lasciare questo programma" << endl; //                 esce
    cout << "Scelta: ";
    cin >> scelta;

    switch (scelta) {
    case 1:
        cout << "Bella scelta! Verrai reindirizzato al menu principale";
        wait();
        menu();
        break;
    case 2:
        cout << "Ok, se proprio insisti, arrivederci e buona giornata! Torna presto";
        wait();
        return;
        break;
    default:
        cout << "Grande, lo prendo per un no, adesso ti reindirizzeremo al menu principale";
        wait();
        menu();
        break;
    }
}

void regole_slot() { //- - - - - - - - - - - - - - - - - - - - - - - regole slot --  --  --  --  --  --  --  --  --  --  --  --  - COMPLETATO
    system("cls");
    int scelta;

    cout << "O-------------------------------------------------------O" << endl;
    cout << "|   R E G O L E   d e l l e   S L O T   M A C H I N E   |" << endl;
    cout << "O-------------------------------------------------------O" << endl;
    cout << " " << endl;
    cout << "- 1: Vengono generati 3 numeri casuali." << endl;
    cout << "      - Se sono 3 numeri diversi:" << endl;
    cout << "         > Perdi, puoi decidere se rigirare o tornare al menu principale." << endl;
    cout << "      - Se sono 3 numeri uguali:" << endl;
    cout << "         > Vinci un premio parziale, puoi decidere se rigirare o tornare al menu principale." << endl;
    cout << "      - Se i 3 numeri sono tutti dei 7:" << endl;
    cout << "         > Vinci il jackpot pieno, puoi decidere se rigirare o tornare al menu principale.\n\n" << endl;
    system("pause");
    regole();
}
void regole_roulette() { //- - - - - - - - - - - - - - - - - - - - - regole roulette --  --  --  --  --  --  --  --  --  --  --  - COMPLETATO
    system("cls");

    cout << "O-----------------------------------------------O" << endl;
    cout << "|   R E G O L E   d e l l a   R O U L E T T E   |" << endl;
    cout << "O-----------------------------------------------O" << endl;
    cout << " " << endl;
    cout << "- 1: Scegli la modalita' di scommessa:" << endl;
    cout << "      - Pari o Dispari:" << endl;
    cout << "         > Puoi scommettere se uscira' un numero pari o un numero dispari." << endl;
    cout << "      - Neri o Rossi:" << endl;
    cout << "         > Puoi scommettere se uscira' un numero rosso o un numero nero." << endl;
    cout << "      - Numero Specifico:" << endl;
    cout << "         > Puoi scommettere su un numero specifico (per puntare sul verde, scegliere questa opzione e inserire '0')." << endl;
    cout << "      - Alto o Basso:" << endl;
    cout << "         > Puoi scommettere se uscira' un numero basso (1-18) o un numero alto (19-36)." << endl;
    cout << "      - Dozzine:" << endl;
    cout << "         > Puoi scommettere se uscira' un numero nella prima dozzina (1-12), nella seconda (13-24), o nella terza (25-36)." << endl;
    cout << "  N.B. questo programma utilizza la ruota europea, quindi NON e' presente il '00'.\n" << endl;
    cout << "- 2: Viene estratto il numero vincente, con annesse caratteristiche (es. 8: pari, nero, basso, prima dozzina).\n" << endl;
    cout << "- 3: Ti verra' comunicata la vittoria o perdita e verra' resettata la schermata della roulette.\n\n" << endl;
    system("pause");
    regole();
}
void regole_dadi() { //- - - - - - - - - - - - - - - - - - - - - - - regole dadi --  --  --  --  --  --  --  --  --  --  --  --  - COMPLETATO
    system("cls");

    cout << "O-----------------------------------O" << endl;
    cout << "|   R E G O L E   d e i   D A D I   |" << endl;
    cout << "O-----------------------------------O" << endl;
    cout << " " << endl;
    cout << "- 1: Scegli il numero che credi uscira'.\n" << endl;
    cout << "- 2: Vengono lanciati i 2 dadi e calcolato il numero vincente." << endl;
    cout << "  N.B. il numero vincente viene calcolato sommando le facce dei due dadi (se le facce sono 5 e 2, il numero vincente e' 7).\n" << endl;
    cout << "- 3: Ti verra' comunicata la vittoria o perdita e verra' resettata la schermata dei dadi.\n\n" << endl;
    system("pause");
    regole();
}
void regole_baccarat() { //- - - - - - - - - - - - - - - - - - - - - regole baccarat --  --  --  --  --  --  --  --  --  --  --  - COMPLETATO
    system("cls");

    cout << "O-------------------------------------------O" << endl;
    cout << "|   R E G O L E   d e l   B A C C A R A T   |" << endl;
    cout << "O-------------------------------------------O" << endl;
    cout << " " << endl;
    cout << "- 1: Scegli se scommettere sul giocatore o sul banchiere." << endl;
    cout << "  N.B. il banchiere non indica il mazziere, bensi' un altra entita' pari al giocatore.\n" << endl;
    cout << "- 2: Sono scoperte 4 carte, due al giocatore e due al banchiere.\n" << endl;
    cout << "- 3: Si calcola il punteggio di entrambe le entita' sommando il valore delle carte." << endl;
    cout << " - 3.1: Le carte dal 10 compreso in su' valgono 0 punti." << endl;
    cout << " - 3.2: Se la somma e' superiore a 10, si prende l'ultima cifra (se le carte sono 5 e 6, la somma e' 11, quindi il punteggio e' 1).\n" << endl;
    cout << "- 4: Se il punteggio di almeno una delle due entita' e' maggiore o uguale a 8, vince quella che ha fatto il punteggio maggiore." << endl;
    cout << " - 4.1: Se il punteggio e' uguale per entrambe, si tratta di un pareggio, non vince nessuno." << endl;
    cout << "  N.B. la vittoria in questa fase e' detta vittoria naturale\n" << endl;
    cout << "- 5: Se il punteggio del giocatore e' 6 o 7, esso non pesca; altrimenti pesca una nuova carta e il suo punteggio viene ricalcolato seguendo la logica del pt 3.\n" << endl;
    cout << "- 6: In base al nuovo punteggio del giocatore e il punteggio del banchiere, si decide se quest'ultimo pesca una nuova carta o no. La logica e' contenuta nella seguente tabella:\n" << endl;
    cout << "           O-----------------O---------------------------------------------O" << endl;
    cout << "           | Terza carta del |                  Banchiere                  |" << endl;
    cout << "           |    Giocatore    |                                             |" << endl;
    cout << "           O-----------------O----------------------O----------------------O" << endl;
    cout << "           |        8        |       0-2 Pesca      |     3-7 non Pesca    |" << endl;
    cout << "           O-----------------O----------------------O----------------------O" << endl;
    cout << "           |       6-7       |       0-6 Pesca      |      7 non Pesca     |" << endl;
    cout << "           O-----------------O----------------------O----------------------O" << endl;
    cout << "           |       4-5       |       0-5 Pesca      |     6-7 non Pesca    |" << endl;
    cout << "           O-----------------O----------------------O----------------------O" << endl;
    cout << "           |       2-3       |       0-4 Pesca      |     5-7 non Pesca    |" << endl;
    cout << "           O-----------------O----------------------O----------------------O" << endl;
    cout << "           |     0-1 9-10    |       0-3 Pesca      |     4-7 non Pesca    |" << endl;
    cout << "           O-----------------O----------------------O----------------------O" << endl << endl;
    cout << " - 6.1: Se il banchiere puo' farlo, pesca una nuova carta, e il suo punteggio viene ricalcolato seguendo la logica del pt 3.\n" << endl;
    cout << "- 7: Visti i nuovi punteggi, vince l'entita' col punteggio maggiore.\n\n" << endl;
    system("pause");
    regole();
}
void regole_blackjack() { // - - - - - - - - - - - - - - - - - - - - regole blackjack -  --  --  --  --  --  --  --  --  --  --  - COMPLETATO
    system("cls");

    cout << "O---------------------------------------------O" << endl;
    cout << "|   R E G O L E   d e l   B L A C K J A C K   |" << endl;
    cout << "O---------------------------------------------O" << endl;
    cout << " " << endl;
    cout << "- 1: Vengono scoperte 3 carte, una del dealer e le 2 del giocatore.\n" << endl;
    cout << "- 2: Viste le carte, il giocatore decide se pescare un'altra carta o no (stand).\n" << endl;
    cout << "- 3: Se il giocatore decide di NON pescare, il dealer mostra la sua carta." << endl;
    cout << " - 3.1: Se la somma delle carte del dealer e' minore di 16, esso ne pesca un altra, e cosi' via finche' non supera i 16 punti o pesca 6 carte in tot*.\n" << endl;
    cout << "- 4: Se il giocatore decide di pescare, gli viene assegnata un'altra carta, poi si procede per pt 3**.\n" << endl;
    cout << "- 5: Se in qualunque momento una delle due entita' ottiene 21 punti, essa vince automaticamente (blackjack); mentre se li supera, essa perde automaticamente (sballato).\n" << endl;
    cout << " " << endl;
    cout << "Specifiche: " << endl;
    cout << " > Dealer stand on 16" << endl;
    cout << " > Blackjack pays 2 to 1" << endl;
    cout << " > No insurance***" << endl;
    cout << " " << endl;
    cout << "* Al dealer vengono assegnate un max di 6 carte per limiazioni tecniche." << endl;
    cout << "** Al giocatore vengono assegnate un max di 3 carte per limitazioni tecniche." << endl;
    cout << "*** L'assicurazione non e' stata implementata per limitazioni tecniche.\n" << endl;
    cout << "Siamo a conoscenza del fatto che cio' riduca di molto le potenzialita' del gioco;" << endl;
    cout << "Per ogni suggerimento, potete contattarci all'indirizzo e-mail 'UfficioReclami@fregancazzo.com'.\n" << endl;

    system("pause");
    regole();
}
void regole_sassoCartaForbici() {//- - - - - - - - - - - - - - - - - regole Sasso-Carta-Forbici  --  --  --  --  --  --  --  --  - COMPLETATO
    system("cls");
    int scelta;

    cout << "O-------------------------------------------------------------------O" << endl;
    cout << "|   R E G O L E   d i   S A S S O  -  C A R T A  -  F O R B I C I   |" << endl;
    cout << "O-------------------------------------------------------------------O" << endl;
    cout << " " << endl;
    cout << " - 1: Appena entrato, scegli che mossa giocare: Sasso, Carta o Forbici" << endl;
    cout << " - 2: Anche la casa sceglie che mossa giocare; poi viene calcolato il vincitore secondo la seguente tabella:\n" << endl;
    cout << "           88============================O===============88" << endl;
    cout << "           ||            MOSSA           |               ||" << endl;
    cout << "           88-------------O--------------O   RISULTATO   ||" << endl;
    cout << "           ||  GIOCATORE  |     CASA     |               ||" << endl;
    cout << "           88=============O==============O===============88" << endl;
    cout << "           ||             |     sasso    |    pareggio   ||" << endl;
    cout << "           ||             O--------------O---------------88" << endl;
    cout << "           ||    sasso    |     carta    |   sconfitta   ||" << endl;
    cout << "           ||             O--------------O---------------88" << endl;
    cout << "           ||             |    forbici   |    vittoria   ||" << endl;
    cout << "           88=============O==============O===============88" << endl;
    cout << "           ||             |     sasso    |    vittoria   ||" << endl;
    cout << "           ||             O--------------O---------------88" << endl;
    cout << "           ||    carta    |     carta    |    pareggio   ||" << endl;
    cout << "           ||             O--------------O---------------88" << endl;
    cout << "           ||             |    forbici   |   sconfitta   ||" << endl;
    cout << "           88=============O==============O===============88" << endl;
    cout << "           ||             |     sasso    |   sconfitta   ||" << endl;
    cout << "           ||             O--------------O---------------88" << endl;
    cout << "           ||   forbici   |     carta    |    vittoria   ||" << endl;
    cout << "           ||             O--------------O---------------88" << endl;
    cout << "           ||             |    forbici   |    pareggio   ||" << endl;
    cout << "           88=============O==============O===============88" << endl << endl;
    system("pause");
    regole();

}

void regole() { // - - - - - - - - - - - - - - - - - - - - - - - - - regole dei giochi   --  --  --  --  --  --  --  --  --  --  - COMPLETATO
    system("cls");
    int scelta;
    
    cout << "O---------------------------------------O" << endl;
    cout << "|   R E G O L E   d e i   G I O C H I   |" << endl;
    cout << "O---------------------------------------O" << endl;
    cout << " " << endl;
    cout << "Di che gioco vorresti visualizzare le regole?" << endl;
    cout << "- 1: Slot Machine" << endl;
    cout << "- 2: Roulette" << endl;
    cout << "- 3: Dadi" << endl;
    cout << "- 4: Baccarat" << endl;
    cout << "- 5: BlackJack" << endl;
    cout << "- 6: Sasso-Carta-Forbici" << endl;
    cout << "- 0: Torna alle impostazioni" << endl;
    cout << "Scelta: ";
    cin >> scelta;

    switch (scelta) {
    case 1:
        regole_slot();
        break;
    case 2:
        regole_roulette();
        break;
    case 3:
        regole_dadi();
        break;
    case 4:
        regole_baccarat();
        break;
    case 5:
        regole_blackjack();
        break;
    case 6:
        regole_sassoCartaForbici();
        break;
    case 0:
        cout << "Verrai reindirizzato alle impostazioni";
        wait();
        impostazioni();
        break;
    default:
        cout << "ATTENZIONE: Inserire un opzione accettabile";
        wait();
        regole();
        break;
    }
}
void crediti() { //- - - - - - - - - - - - - - - - - - - - - - - - - crediti del programmone --  --  --  --  --  --  --  --  --  - COMPLETATO
    system("cls");
    
    cout << "O---------------------------------------------------O" << endl;
    cout << "|   C R E D I T I   d e l   P R O G R A M M O N E   |" << endl;
    cout << "O---------------------------------------------------O" << endl;
    cout << " " << endl;
    cout << "Programmatori:" << endl;
    cout << "                   > Carletti Stefano" << endl << endl;
    cout << "Menzioni onorevoli:" << endl;
    cout << "                   > Trotta Simone; - - - - - - - - - - - - - - - - - - - Idea iniziale di un programma che unisce piu' giochi d'azzardo." << endl;
    cout << "                   > WikiHow; - - - - - - - - - - - - - - - - - - - - - - Regole e funzionamento del Baccarat." << endl;
    cout << "                   > StackOverflow; - - - - - - - - - - - - - - - - - - - Funzioni base del c++ ed esempi di codice." << endl;
    cout << "                   > Laboratorio Info2, I.S. Gobetti; - - - - - - - - - - In parte luogo di sviluppo di entrambe le edizioni del programmone." << endl;
    cout << "                   > Capa Suprema ; - - - - - - - - - - - - - - - - - - - Finanziatrice del PC su cui e' stato scritta per la maggior parte di entrambe le edizioni del Programmone." << endl;
    cout << "                   > Guccini Francesco; - - - - - - - - - - - - - - - - - Cantautore che ha intrattenuto i programmatori durante la maggior parte della scrittura di entrambe le edizioni del Programmone." << endl;
    cout << "                   > Di Salvo Giulia; - - - - - - - - - - - - - - - - - - Professoressa che ha intrattenuto i programmatori durante la permanenza e la scrittura nel Lab Info2." << endl;
    cout << "                   > S.ta Trinita', Clero e tutto cio' ch'e' Sacro; - - - Supporto morale ai programmatori." << endl << endl;
    system("pause");
    impostazioni();
}

void impostazioni() { // - - - - - - - - - - - - - - - - - - - - - - aiuto   --  --  --  --  --  --  --  --  --  --  --  --  --  - COMPLETATO
    system("cls");
    int scelta;

    cout << "O-----------------------------O" << endl;
    cout << "|   I M P O S T A Z I O N I   |" << endl;
    cout << "O-----------------------------O" << endl;
    cout << " " << endl;
    cout << "Cosa vorresti fare?" << endl;
    cout << "- 1: Regole dei giochi" << endl;
    cout << "- 2: Crediti" << endl;
    cout << "- 3: Attiva la Debug Mode." << endl;
    cout << "- 0: Torna al menu principale" << endl;
    cout << "Scelta: ";
    cin >> scelta;

    switch (scelta) {
    case 1:
        regole();
        break;
    case 2:
        crediti();
        break;
    case 3:
        debugLogin();
        break;
    case 0:
        cout << "Verrai reindirizzato al menu principale";
        wait();
        menu();
        break;
    default:
        cout << "ATTENZIONE: Inserire un opzione accettabile";
        wait();
        impostazioni();
        break;
    }
    
}

void easter_egg69() { // - - - - - - - - - - - - - - - - - - - - - - :D  --  --  --  --  --  --  --  --  --  --  --  --  --  --  - COMPLETATO
    system("cls");
    Sleep(300);
    cout << "     __      ___" << endl;
    cout << "    / /_    / _ \\" << endl;
    cout << "   | \'_ \\  | (_) |" << endl;
    cout << "   | (_) |  \\__, |" << endl;
    cout << "    \\___/     /_/" << endl;
    Sleep(500);
    menu();
}
void easter_egg104() { //- - - - - - - - - - - - - - - - - - - - - - :D  --  --  --  --  --  --  --  --  --  --  --  --  --  --  - COMPLETATO
    system("cls");
    int scelta;

    cout << "O-----------O" << endl;
    cout << "|   1 0 4   |" << endl;
    cout << "O-----------O" << endl;
    cout << " " << endl;
    cout << "Che articolo vorresti visionare?" << endl;
    cout << "[  1 ] | [  2 ] | [ 2.1] | [  3 ] | [  4 ]" << endl;
    cout << "[  5 ] | [  51] | [  6 ] | [  7 ] | [  8 ]" << endl;
    cout << "[  9 ] | [ 10 ] | [ 11 ] | [ 12 ] | [ 13 ]" << endl;
    cout << "[ 14 ] | [ 15 ] | [ 16 ] | [ 17 ] | [ 18 ]" << endl;
    cout << "[ 19 ] | [ 20 ] | [ 21 ] | [ 22 ] | [ 23 ]" << endl;
    cout << "[ 24 ] | [ 25 ] | [ 26 ] | [ 27 ] | [ 28 ]" << endl;
    cout << "[ 29 ] | [ 30 ] | [ 31 ] | [ 32 ] | [ 33 ]" << endl;
    cout << "[ 34 ] | [ 35 ] | [ 36 ] | [ 37 ] | [ 38 ]" << endl;
    cout << "[ 39 ] | [ 40 ] | [ 41 ] | [ 411] | [ 412]" << endl;
    cout << "[ 42 ] | [ 43 ] | [ 44 ] | [  0 ] |" << endl;
    cout << "Scelta: ";
    cin >> scelta;
    cout << endl;

    switch (scelta) {
    case 1:
        cout << "La Repubblica:\na) Garantisce il pieno rispetto della dignita' umana e i diritti di liberta' e di autonomia della persona handicappata e ne promuove la piena integrazione nella famiglia, nella scuola, nel lavoro e nella societa';\nb) previene e rimuove le condizioni invalidanti che impediscono lo sviluppo della persona umana, il raggiungimento della massima autonomia possibile e la partecipazione della persona handicappata alla vita della collettivita',\n   nonche' la realizzazione dei diritti civili, politici e patrimoniali;\nc) persegue il recupero funzionale e sociale della persona affetta da minorazioni fisiche, psichiche e sensoriali e assicura i servizi e le prestazioni per la prevenzione, la cura e la riabilitazione delle minorazioni, nonche'\n   la tutela giuridica ed economica della persona handicappata;\nd) predispone interventi volti a superare stati di emarginazione e di esclusione sociale della persona handicappata." << endl;
        system("pause");
        menu();
        break;
    default:
        cout << "Non ho voglia di stamparli tutti, ma puoi trovare la legge completa al sito: https://www.normattiva.it/uri-res/N2Ls?urn:nir:stato:legge:1992-02-05;104!vig=" << endl;
        system("pause");
        menu();
        break;
    }
}

void menu() { // - - - - - - - - - - - - - - - - - - - - - - - - - - menu principale --  --  --  --  --  --  --  --  --  --  --  - COMPLETATO
    system("cls");
    int scelta;

    cout << "O-------------------------------------------------------O" << endl;
    cout << "|   B E N V E N U T O   N E L   P R O G R A M M O N E   |" << endl;
    cout << "O-------------------------------------------------------O" << endl;
    cout << " " << endl;
    cout << "Che gioco vorresti fare?" << endl;
    cout << "- 1: Slot Machine" << endl;
    cout << "- 2: Roulette" << endl;
    cout << "- 3: Dadi" << endl;
    cout << "- 4: Baccarat" << endl;
    cout << "- 5: Blackjack" << endl;
    cout << "- 6: Sasso-Carta-Forbici\n" << endl;
    cout << "- 9: ! Impostazioni !" << endl;
    cout << "- 0: Esci dal Programmone\n" << endl;
    cout << "Scelta: ";
    cin >> scelta;

    switch (scelta) {
        case 1:
            slot();
            break;
        case 2:
            roulette();
            break;
        case 3:
            dadi();
            break;
        case 4:
            baccarat();
            break;
        case 5:
            blackjack();
            break;
        case 6:
            sassoCartaForbici();
            break;
        case 9:
            impostazioni();
            break;
        case 0:
            arrivederci();
            break;
        case 69:
            easter_egg69();
            break;
        case 104:
            easter_egg104();
            break;
        default:
            cout << "ATTENZIONE: inserire un'opzione valida!";
            wait();
            menu();
            break;
    }
}

int main() {    //main
    menu();
    return 0;
}

// Programmone V2 creato interamente da Carletti Stefano. Ogni copia deve essere esplicitamente approvata da quest'ultimo!