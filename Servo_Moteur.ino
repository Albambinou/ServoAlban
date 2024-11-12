/*
 * --- Commande Servo Moteur MG 995 ---
 * 
 * - Programme basique sur Arduino Mega
 * - IDE Arduino 2.3.3
 * 
 * --- Constituants :
 *   - Servo moteur MG 995
 *   - Potentiomètre 10 KOhm
 * 
 * Version 1 : 12 Novembre 2024
 */

// --- Inclusion des bibliothèques ---
#include <Servo.h>

// --- Déclaration des variables et autres objets ---
Servo myServo;
const int potPin = A0;       // Le curseur du potentiomètre est connecté à la broche analogique A0
int potVal;                  // Valeur numérique du potentiomètre [0 à 1023]
int angle;                   // Valeur de l'angle du moteur
const int Angle_Mini = 0;    // Borne inférieure de l'angle
const int Angle_Maxi = 179;  // Borne supérieure de l'angle

void setup() {
  myServo.attach(3);         // Attache le servo à la broche numérique 3 pour la commande PWM
  Serial.begin(9600);        // Initialise la liaison série à 9600 bauds pour la communication avec le PC
}

void loop() {
  Serial.println("\nNouvelle commande d'angle !!\n");

  // --- Lecture de la commande angulaire ---
  potVal = analogRead(potPin);  // Lit la valeur du potentiomètre
  Serial.print("Valeur du potentiomètre : ");
  Serial.print(potVal);

  // Mise à l'échelle de la valeur angulaire en fonction de la plage de conversion numérique
  angle = map(potVal, 0, 1023, Angle_Mini, Angle_Maxi);

  // --- Affichage de l'angle demandé ---
  Serial.print(" ; angle : ");
  Serial.println(angle);

  // Applique l'angle au servo
  myServo.write(angle);

  // Délai de 5 secondes avant la prochaine lecture
  delay(5000);
}
