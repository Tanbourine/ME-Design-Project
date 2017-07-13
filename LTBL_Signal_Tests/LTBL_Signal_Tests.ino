const int leftIn = 7;
const int rightIn = 8;
const int brakeIn = 9;
//const int brakeIn4wire = 9;
//const int brakeIn5wire = 10;
const int hazardsIn = 11;

const int leftOut = 2;
const int rightOut = 3;
const int brakeOut = 4;
//const int brakeOut4wire = 4;
//const int brakeOut5wire = 5;
const int hazardsOut = 6;

// OPTIONAL
//const int hazardsOut1 = 5;
//const int hazardsOut2 = 6;

unsigned long previousMillisLeft = 0;
unsigned long previousMillisRight = 0;
unsigned long previousMillisHazards = 0;

const long interval = 500;

int BRAKE;
//int BRAKE4wire;
//int BRAKE5wire;

int LEFT;
int leftState = LOW;

int RIGHT;
int rightState = LOW;

int HAZARDS;
int hazardsState = LOW;

void setup() 
{
  pinMode(leftIn, INPUT);
  pinMode(rightIn, INPUT);
  pinMode(brakeIn, INPUT);
  //pinMode(brakeIn4wire, INPUT);
  //pinMode(brakeIn5wire, INPUT);
  pinMode(hazardsIn, INPUT);
  
  pinMode(leftOut, OUTPUT);
  pinMode(rightIn, INPUT);
  pinMode(brakeOut, OUTPUT);
  //pinMode(brakeOut4wire, OUTPUT);
  //pinMode(brakeOut5wire, OUTPUT);
  pinMode(hazardsOut, OUTPUT);

  // OPTIONAL
  //pinMode(hazardsOut1, OUTPUT);
  //pinMode(hazardsOut2, OUTPUT);
}

void loop() 
{
  RIGHT = digitalRead(rightIn);  
  LEFT = digitalRead(leftIn);
  HAZARDS = digitalRead(hazardsIn);
  BRAKE = digitalRead(brakeIn);
  //BRAKE4wire = digitalRead(brakeIn4wire);
  //BRAKE5wire = digitalRead(brakeIn5wire);
  
  unsigned long currentMillis = millis();

  // BRAKE SIGNAL
  if (BRAKE == HIGH) 
  {
    digitalWrite(brakeOut, HIGH);
  }
  else
  {
    digitalWrite(brakeOut, LOW);
  }

//  if (BRAKE5wire == HIGH) 
//  {
//    digitalWrite(brakeOut5wire, HIGH);
//  }
//  else
//  {
//    digitalWrite(brakeOut5wire, LOW);
//  }

//  if (BRAKE4wire == HIGH) 
//  {
//    digitalWrite(brakeOut4wire, HIGH);
//    digitalWrite(leftOut, HIGH);
//    digitalWrite(rightOut, HIGH);
//  }
//  else
//  {
//    // Testing needs to be done for this else statement. leftOut and rightOut may not need to be written LOW here
//    digitalWrite(brakeOut4wire, LOW);
//    digitalWrite(leftOut, LOW);
//    digitalWrite(rightOut, LOW);
//  }

  // LEFT SIGNAL
  if ( (currentMillis - previousMillisLeft >= interval) && (LEFT == HIGH) ) 
  {
    previousMillisLeft = currentMillis;
  
    if (leftState == LOW) 
    {
      leftState = HIGH;
    } 
    else 
    {
      leftState = LOW;
    }
  digitalWrite(leftOut, leftState);
  }
  else if ( (currentMillis - previousMillisLeft >= interval) && (LEFT == LOW) ) 
  {
    digitalWrite(leftOut, LOW);
  }

  // RIGHT SIGNAL
  if ( (currentMillis - previousMillisRight >= interval) && (RIGHT == HIGH) ) 
    {
      previousMillisRight = currentMillis;
    
      if (rightState == LOW) 
      {
        rightState = HIGH;
      } 
      else 
      {
        rightState = LOW;
      }
    digitalWrite(rightOut, rightState);
    }
  else if ( (currentMillis - previousMillisRight >= interval) && (RIGHT == LOW) ) 
  {
    digitalWrite(rightOut, LOW);
  }

  // HAZARDS SIGNAL
  if ( (currentMillis - previousMillisHazards >= interval) && (HAZARDS == HIGH) ) 
    {
      previousMillisHazards = currentMillis;
    
      if (hazardsState == LOW) 
      {
        hazardsState = HIGH;
      } 
      else 
      {
        hazardsState = LOW;
      }
      digitalWrite(hazardsOut, hazardsState);

      // OPTIONAL
      //digitalWrite(hazardsOut1, hazardsState);
      //digitalWrite(hazardsOut2, hazardsState);
    }
    else if ( (currentMillis - previousMillisHazards >= interval) && (HAZARDS == LOW) )
    {
      digitalWrite(hazardsOut, LOW);

      // OPTIONAL
      //digitalWrite(hazardsOut1, LOW);
      //digitalWrite(hazardsOut2, LOW);
    }
    
}
