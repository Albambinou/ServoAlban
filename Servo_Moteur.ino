/*
 * --- Commande Servo Moteur MG 995
 * 
 * - Programme basique sur Arduino Mega
 * - IDE Arduino 2.3.3
 * 
 * --- Constituants :
 * - Servo moteur MG 995
 * - Potentiomètre 10 KOhm
 * 
 * Version 1 : 12 Novembre 2024
 */

 // --- inclusion des bibliothèques
 #include <Servo.h>
 
// --- Déclaration des variables et autres objets
Servo myServo;
int const potPin = A0;      // Le curseur du potentiometre est connecté à la broche analogique A0 de l'arduino
int potVal;                 // Variable de la position du curseur apr_s conversion numérique [0 à 1023] 10 bits
int angle;                  // Variable de fixation de l'angle axe moteur
int const Angle_Mini = 0;   // Fixe la borne inférieur de la variation angulaire de l'axe moteur
int const Angle_MAxi = 179; // Fixe la borne supérieur de la variation angulaire de l'axe moteur

void setup()
{
  myServo.attach(3);       // Fonction déclarant que la MLI du servo est connectée àn la broche digital 3
  Serial.begin(9600);      // Initialisation de la liaison série PC <---> Arduino
}

void loop()
{
  Serial.println("");
  Serial.println("Nouvelle commande d'angle !!");
  Serial.println("");

    // --- Lecture de la commabde angulaire
  potVal = analogRead(potPin);  // Lecture de la valeur du potentiomètre
  Serial.print("Valeur du potentiomètre : ");
  Serial.print(potVal);

  // Mise à l'échelle de la valeur angulaire proportionnellement à l'amplitude de la conversion numérique
  angle = map(potVal, 0, 1023, Angle_Mini, Angle_MAxi);

  //  -- Affichage de l'angle demandé
  Serial.print(" ; angle : ");
  Serial.println(angle);

  myServo.write(angle);
  delay(5000);
}
