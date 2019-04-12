#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <sys/ioctl.h>
#include <unistd.h>

using namespace std;

string art = "WWNNWWWWWWWWNXNNWWNNNNWWWWWWWNNNWWWNXXNWWWNXkoooodxkOkk0NWWWXXNWWWNNNWWWWWWWWNNNWWWNXNWWWWNNWWNWWWWNNNNWWWNNNNNWWWWWNNNWWWWNNNNWWNNNNNNWWWX:    'okKKxxNWWWNNNNWWWWWNNNWWWWNNNNWWWNNNNNWWWWNNNNWWWWNNNNNWWWNNNWWWWNNNNNWNKxkXNNWWWWNNNNNWK;    ,xKWWOxXWNWWNNNNNWWWNXNNNWWWWNNNWWWWNNNNNWWWWNNNWWWWNNNNNWWWWNNNWWWWNKko;. .lXNNNWWWNNNNWK,    ;OXWW0xXNNNWWWNNNWWNOxkO0XWWWWWNNNWWWWNNNWWWWNNNNNWWWWNNNNWWWNNNNWXxc'       cKNNWWWXK0Oxl.    ;OXWW0ok00XNWWWWNNKxkXNKOkOOKWWNNNNWWWWNNNNWWWNNNNNNWWWWNNNWWWNNNWO'          ;xdlc;,..        :0XNWNK0OOOOOO0KX0dkNWWWWNK0xxXWNNNNWWWWWWNNWWWWNNNNNWWNWNNNNWWWNNNO'                          :0XWNNWWWWNNXK00kx0NNNNWWNWXxkNWWWNNNWWWWNNNNNWWWWNNNNWWWNNNNNWWWWNNO,               ..,;:ccll,.',;:cloxk0XNNWWWWWNNNNWWWKx0NNNWWWNNNNWWWWNNNNWWWWWNNNWWWWNNNNWWWNWXc         .':ldkOKNWWWWNWx.        ..';cdOXWWWWNNNW0xKNNNNNWWNWWNNNWWWWNNNNWWNNWNNWWWWWNNNWWKo'       ':oOXWWX0xdollcc::''cclc::;'..    .'cxKNNNNN0xOXWNNNNWWWNNNNNWWWWNNNNWWWW0ox0NWWWWN0l'      'ckXWNKkl;'.          lXNWWWWNXKOxo:'    .:dKNNNN0kOKWNNNWWWWNNNNWWWWWNNNWWO,  .;oOXKo.     .;dKNWNOc.               lXNNNWWWNNNNNWXkl'    .lOXNNNKkOXNNNNX0Ok0NNWWWWNNNNk'      .'.     .:kNWNNk;.                 lNNNNNWWWWNNNNNWWKd,    .:OXNWN0kOOOOOOKKO0NNNWWWNXd.              ,kNWWW0c.                   oWNNNNNWWWWWNNNWWWNKo.    .c0NNWX0OKXNNWWNOOXWNWWWO'             .oXNNWNk'                     dWWWNNNNNWWWNNNNNWWWNO,     .xXWNWWWNNNNWWNOkXNNNWN0d;.         'kNWNWXo.                     .dWWWWWNNNWWWWNNNNNWWNWKc     .cKNNWWWNNNNNN0dONNNNWWWN0d'      ,0WWWWNo.                      .dWWNWWNNNNNWWWWNNNNWWWWXc      ;0NNWWWWX0O00KNWWNNNWWWNK:     ,0NNNWWO.                       .dWNNNWWNNNNNWWWWWNNNWWWWK;      ;KNNWNOO0KNNWWWNNNNNNWWd.    'OWNNNWXc                        .xMWNNNWWWNNNNNWWWNWNNNWWWx.      :KNNNOONWNNNWWWWNNNNW0'    .dWWWNNNO'                        .kMWNNNNWWWWNNNWWWWNNNNNNWK,      .dNNNXk0WNNNNNWWWWNNNo     :KWWWWWWx.                        .kMWNNNNNNWWWWNNNWWWWNNNNWN:       '0WNN0ONWNNNXKKKKKKk'    .dNNNWWWWx.   ..                   .kMWWWWNNNWWWNNWNNNWWNNNNNNl        oNNWKxKWWWWo.......     '0WNNNWWWk.   :x'                  .kWWWWWWNNNNWWWWNNNWXooNWNXc        ;XWNNkxKKXKc            :XWWNNNWWk.   c0,                  .OMWNNWWWWNNNWWWWNNNO.:NWNX:        .OWWWKOO000c            :NWWNNNNWO.   lO'                  '0MNNNNWWWNNNNWWWWWWx.:NWW0,        .xWWWWWNNNWc            :XWWWNNNWK;   ox.    .....         '0MWNNNNWWWNNNNWWWWWO':XWWk.        .xWNWWWWWNNo......      :XNNWWWWNNd. .o,  .:xO00OOkdc.     ,KMWNNNKxl:;;;;:lONWXc;0WNl         .kNNWWWWNNNK0000OOd.    'OWNNNWWWWKl,c,  .kNWWWNNNNNNKl.   ,KMWWKc.         .cKW0:dNk.         ,KWNNK0KKK0NNNNWWWNl    .dNNNNWWWNWNk,   lNNNWWWWNNNNNX:   ,KWWX:             oNWOc;.          lNWNKdkKKKKNNNNNWWWk.    ;KWNNNNWWNd.    oNWNNNNWWWWNXO,   ;KWWK:             cNNW0;          .kWWWOxXWNWWWWNNNNWWNl    .oNWNNNNNo.     'ONNNX0kxol:,.    ;XWNNXxl:,..      .dNNWWKc         lXNWXxONNNNWWWWNNNNNW0,    .xWNNNN0'       .;:;..         ..'kNNNNNWWWX0kdc,':xNWNNNWX;       ;KWNNOkNWWNNNNWWNNNWNXk,     .kWWNNK;                      ld..:kWWNNNWWWWNNNNNWWNNWNWNc      ,0WNNOxXWWWNNNNNWWN0o:'.       .kWWWNk'     .:clllc;.      ,Kk.  ;KWNNNNNXOkxxk0XWWNNNNO'     ,OWWWNkdOXWWWNNNNNNx.            .dXWWW0c,,ckXNNWWWNd.     .dNl.  .xWWNNNKl.    .'cONWNk,     :0WNWWWNXOkkOXWWNNNNXl.            .:0WWNNNXNWWWWNNWX:      .cc.;o;;kWWWWNNO'       .,:,.    .dXWNNNWWWWNNXkdKWWWNNWNo.       .     .oXWNNNWNWWNNNNNk.         cNNNNNNWWWNl               .;ONWWWWNNNWWWWXkONWWWWNNNNx.  .'cxOd.     'oKWNNNNWWWNNNX;..  .    cNWWXKXN0KO.             .;kXNNNKOO0NWNNWXk0NNNWWWWWNNNkld0XNNNWKl.     .cONNNNNWWWNNl:x'.l;   ;XMMx;O0;lo.           .cONWWN0O0XX0000KOkKWWNNNNWWWNNNNNWWWWNNNWW0l.     .,lOXNWWWWW00K:,Oo   ,0MWl.dx...         .:dKNNWNKOOKNNWWWX0OOXWWWNNNNNWWWWNNNNWWWNNNNNNWKl.      .'cdOXWWWWN00N0ol'.:ol' ..        .'cd0WWNNX0O0XWNNNNWWWWWNNNWWWWNNNNWWWWWNNNWWWWNNNNNNd.          .':ldkOKXNWWWd.          .,:ox0XNNNWWWNxxNWWWWNNNNWWWWNNNNNWWWNNNNNWWNNWNNNWWWWNNXo.                 ..',;::''::::clodxO0XNWWWWNNNNWWW0xKNNWWWWNNNWWWWNNNNNWWWWNNNNWWWNNNNNNWWWXc          .;,..           .dWNNNNWWWWNNNXK0OKWWNNNWWW0x0NNWWWWNNNNWWWWNNNNNWWWWNNNWWWWNNNNNWWXx:.       'kWWXOxoc:,'.    .dWWWNK0000000000Ok0NWNNNWWNkxXNWWWWNNNNNNWWWWNNNNWWWNNNNNWWWWNNNWWWWNKxc'.  ;0NNNWWWWNNNXd.   .dWWWNdxK0KNWWWNNNXk0NNNK0000XNNNNWWWWNNNNNWWWNWNNNWWWNNNNNWWWNWNNNWWWNNNXOodKNNNNNWWWWNNNk.   .dWNWXdkWNNNNWWWWNNXOk0000XNWWWWWNNNWWWWNNNWWWWNWNNNWWWWNNNNWWWNNNNNWWWWWNNWWWWWNNNWWWWNNWk.   .xNNWKdOWNNNNNWWNNNNXKXWWWNNNWWWWNNNNNWWWWNNNWWWWNNNNNWWWWNNNNWWWNNNNWWWNNNNNWWWWWNNNWWWNN0:''';d0O0xdKWWWNNNNWWWNNNNNWWWWWNNWWWWWNNNWWWWNNNNNWWWNXXNWWWWNNWWWWWWWWNNNWWWNXNNWWWNNWWNWWWWWXKXXXXK00KXWWWWNWWNNWWWWNXNNWWWNNNWWWWWWWNNNWWWNXXNW";

string start = "-----------------------------------starting-data-inload----------------------------------------";
string endInload = "--------------------------------------ending-inload--------------------------------------------";

void center(int, bool);

int main() {

    srand(1);

    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    int col = w.ws_col;
    col -= 95;
    col /= 2;

    center(col, false);
    for(int i=0; i<start.length(); i++){
        cout << start[i]<< flush;
        this_thread::sleep_for(chrono::milliseconds(50));
    }
    center(col, false);

    cout << endl;

    //print emblem
    for(int i=1; i<50; i++) {
        center(col, true);
        for(int j=0; j<95; j++) {
            cout << art[i*95 + j] << flush;
            this_thread::sleep_for(chrono::milliseconds(1));
        }
        center(col, true);
        cout << endl;
    }

    center(col, false);
    for(int i=0; i<endInload.length(); i++){
        cout << endInload[i] << flush;
        this_thread::sleep_for(chrono::milliseconds(50));
    }
    center(col, false);

    cout << endl;
}

void center(int col, bool mode) {
    char nw[2] = {'W','N'};

    for(int i=0; i<col; i++){
        if(mode) {
            cout << nw[rand() % 2] << flush;
        }
        else {
            cout << '-' << flush;
        }
        this_thread::sleep_for(chrono::milliseconds(1));
    }
}