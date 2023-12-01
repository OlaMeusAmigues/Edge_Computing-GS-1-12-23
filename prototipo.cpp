#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd_1(0);

int dist_min = 250;

int tempo_alterar = 5;

int dist_1 = 0;
int dist_2 = 0;
int dist_3 = 0;
int dist_4 = 0;
int dist_5 = 0;

int trigger_1 = 13;
int trigger_2 = 12;
int trigger_3 = 11;
int trigger_4 = 10;
int trigger_5 = 9;

int echo_1 = 8;
int echo_2 = 7;
int echo_3 = 6;
int echo_4 = 5;
int echo_5 = 4;

int check_1 = 0;
int check_2 = 0;
int check_3 = 0;
int check_4 = 0;
int check_5 = 0;

bool ocupado_1 = false;
bool ocupado_2 = false;
bool ocupado_3 = false;
bool ocupado_4 = false;
bool ocupado_5 = false;

int cadeiras = 5;
int num_ocupacao;
int porcentagem_ocupacao;

char* estado_1 = "livre";
char* estado_2 = "livre";
char* estado_3 = "livre";
char* estado_4 = "livre";
char* estado_5 = "livre";

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
 
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600);
  lcd_1.begin(16, 2);
  lcd_1.print("Assentos em uso:");

}

void loop()
{
  
  dist_1 = 0.01723 * readUltrasonicDistance(trigger_1, echo_1);
  dist_2 = 0.01723 * readUltrasonicDistance(trigger_2, echo_2);
  dist_3 = 0.01723 * readUltrasonicDistance(trigger_3, echo_3);
  dist_4 = 0.01723 * readUltrasonicDistance(trigger_4, echo_4);
  dist_5 = 0.01723 * readUltrasonicDistance(trigger_5, echo_5);
  
  if (dist_1<dist_min){
    check_1++;
  }else if (check_1>tempo_alterar){
    check_1 = tempo_alterar;
  }else if (check_1>0){
    check_1--;
  }//temporizador 1
  if (dist_2<dist_min){
    check_2++;
  }else if (check_2>tempo_alterar){
    check_2 = tempo_alterar;
  }else if (check_2>0){
    check_2--;
  }//temporizador 2
  if (dist_3<dist_min){
    check_3++;
  }else if (check_3>tempo_alterar){
    check_3 = tempo_alterar;
  }else if (check_3>0){
    check_3--;
  }//temporizador 3
  if (dist_4<dist_min){
    check_4++;
  }else if (check_4>tempo_alterar){
    check_4 = tempo_alterar;
  }else if (check_4>0){
    check_4--;
  }//temporizador 4
  if (dist_5<dist_min){
    check_5++;
  }else if (check_5>tempo_alterar){
    check_5 = tempo_alterar;
  }else if (check_5>0){
    check_5--;
  }//temporizador 5
  
  
    
  if (check_1 >= tempo_alterar){
    ocupado_1 = true;
    estado_1 = "ocupado";
  }else if(check_1 == 0){
    ocupado_1 = false;
    estado_1 = "livre";
  }
  Serial.print("Assento 1: ");
  Serial.println(estado_1);//estado do assento 1
  
  if (check_2 >= tempo_alterar){
    ocupado_2 = true;
    estado_2 = "ocupado";
  }else if(check_2 == 0){
    ocupado_2 = false;
    estado_2 = "livre";
  }
  Serial.print("Assento 2: ");
  Serial.println(estado_2);//estado do assento 2
  
  if (check_3 >= tempo_alterar){
    ocupado_3 = true;
    estado_3 = "ocupado";
  }else if(check_3 == 0){
    ocupado_3 = false;
    estado_3 = "livre";
  }
  Serial.print("Assento 3: ");
  Serial.println(estado_3);//estado do assento 3
  
  if (check_4 >= tempo_alterar){
    ocupado_4 = true;
    estado_4 = "ocupado";
  }else if(check_4 == 0){
    ocupado_4 = false;
    estado_4 = "livre";
  }
  Serial.print("Assento 4: ");
  Serial.println(estado_4);//estado do assento 4
  
  if (check_5 >= tempo_alterar){
    ocupado_5 = true;
    estado_5 = "ocupado";
  }else if(check_5 == 0){
    ocupado_5 = false;
    estado_5 = "livre";
  }
  Serial.print("Assento 5: ");
  Serial.println(estado_5);
  Serial.println();//estado do assento 5
  
  
  
  num_ocupacao = 0;
  if( ocupado_1 == true ){
    num_ocupacao++;
  }
  if( ocupado_2 == true ){
    num_ocupacao++;
  }
  if( ocupado_3 == true ){
    num_ocupacao++;
  }
  if( ocupado_4 == true ){
    num_ocupacao++;
  }
  if( ocupado_5 == true ){
    num_ocupacao++;
  }
  

  porcentagem_ocupacao = int(num_ocupacao*100/cadeiras);
  
  lcd_1.setCursor(0, 1);
  lcd_1.setBacklight(1);
  lcd_1.print(porcentagem_ocupacao);
  lcd_1.print("%  ");
  
  delay(1000); 
}
