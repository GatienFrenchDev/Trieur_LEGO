#include <Wire.h>
#include "Adafruit_TCS34725.h"

/* Connect SCL    to analog 5
   Connect SDA    to analog 4
   Connect VDD    to 3.3V DC
   Connect GROUND to common ground
   
   Connect Switch to Digital 2
*/

/* Initialise with default values (int time = 2.4ms, gain = 1x) */
// Adafruit_TCS34725 tcs = Adafruit_TCS34725();

//variable pour le bouton poussoir
int switchState = 0;
//variables pour les valeurs par défaut du capteur
int r_initial = 0;
int g_initial = 0;
int b_initial = 0;

/* Initialise with specific int time and gain values */
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_614MS, TCS34725_GAIN_1X);

void setup(void) {
  Serial.begin(9600);
  pinMode(2, INPUT); // pin pour le bouton poussoir

  if (tcs.begin()) {
    Serial.println("Capteur trouvé !");
  } else {
    Serial.println("Aucun capteur trouvé !");
    while (1);
  }

    // Execute un test pour les valeurs initials (à vide)
    uint16_t r, g, b, c, colorTemp, lux;
    tcs.getRawData(&r, &g, &b, &c);
    r_initial = r;
    g_initial = g;
    b_initial = b;
    Serial.println("Test Fait");
    Serial.println("Pret");
    /*
    Serial.println("Valeur du test :");
    Serial.println(r_initial);
    Serial.println(g_initial);
    Serial.println(b_initial);
    */

}

void loop(void) {
  switchState = digitalRead(2);
  if(switchState == HIGH){
    // fais le test de couleur
    uint16_t r, g, b, c, colorTemp, lux;
    tcs.getRawData(&r, &g, &b, &c);

    /*
    Serial.println("Valeur Objet :");
    Serial.println(r);
    Serial.println(g);
    Serial.println(b);
    */

    // renvoie la différence
    int delta_r = r-r_initial;
    int delta_g = g-g_initial;
    int delta_b = b-b_initial;
    Serial.println("=====================");
    Serial.print("Différence Rouge : ");
    Serial.println(delta_r);
    Serial.print("Différence Vert : ");
    Serial.println(delta_g);
    Serial.print("Différence Bleu : ");
    Serial.println(delta_b);
    Serial.println("=====================");
    

  }
  
}
