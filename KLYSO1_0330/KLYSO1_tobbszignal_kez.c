#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

/* 2. feladat:
Készítsen el a következő feladatot, melyben egy szignálkezelő több szignált is tud kezelni:
a.) Készítsen egy szignál kezelőt (handleSignals), amely a SIGINT (CTRL + C) vagy
SIGQUIT (CTRL + \) jelek fogására vagy kezelésére képes.
b.) Ha a felhasználó SIGQUIT jelet generál (akár kill paranccsal, akár billentyűzetről a CTRL
+ \) a kezelő egyszerűen kiírja az üzenetet visszatérési értékként – a konzolra.
c.) Ha a felhasználó először generálja a SIGINT jelet (akár kill paranccsal, akár
billentyűzetről a CTRL + C), akkor a jelet úgy módosítja, hogy a következő alkalommal
alapértelmezett műveletet hajtson végre (a SIG_DFL) –kiírás a konzolra.
d.) Ha a felhasználó másodszor generálja a SIGINT jelet, akkor végrehajt egy alapértelmezett
műveletet, amely a program befejezése - kiírás a konzolra.
*/

void handleSignals();

int main(){
signal(SIGINT, handleSignals);
signal(SIGQUIT, handleSignals);
for (int i=0; i<10; i++){
	printf("Waiting for signal x%d\n",i+1);
	pause();
}
return 0;
}

void handleSignals(int sig){
char desc[50];	//Itt fogjuk tárolni a signal-t

switch(sig){

	case 2: {
	strcpy(desc, "Interrupt"); //Ha ide ér a program akkor egy interrupt signal-t kaptunk, ezért átíruk a desc változót interruptra
	signal(SIGINT, SIG_DFL);
	printf("\nCTRL + C-vel kiléphet");
	break;
	}

	case 3: {
	strcpy(desc, "Quit");	//Ha ide ér a program akkor egy quit signal-t kaptunk, ezért átíruk a desc változót quit-re
	break;
	}

	default: {
	break;
	}
}

printf("Jel: %s\n", desc); //Kiírjuk a kapott signalt
}