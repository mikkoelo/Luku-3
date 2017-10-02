#include "musical_notes.h" // tässä liitetään luomasi nuottitiedosto varsinaiseen ohjelmaan

int speakerPin = 9;   // portit määritellään muuttujina: 
int tiltPin = 2;      // niihin viitataan ohjelmassa hyvin monta kertaa


void setup() {
  pinMode(speakerPin, OUTPUT);     // portti 9 on piezo eli output
  pinMode(tiltPin, INPUT_PULLUP);  // portti 2 on tilt-kytkin eli input
  Serial.begin(9600);              // debuggaus on aina paikallaan
}

void loop() {
   int which = random(9);           // arvotaan kokonaisluku 0-8 ja tallennetaan se muuttujaan which
   if (digitalRead(tiltPin) == HIGH) {
     which = 9; // muuta which-muuttujan arvoksi 9
   }
   Serial.println(which); // tulosta which-muuttuja serial monitoriin
   
   delay(1500); // lisää 1-2 sekunnin viive, jotta arvot ehtii lukea monitorista
}
