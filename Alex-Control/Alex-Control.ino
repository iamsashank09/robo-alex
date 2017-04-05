
String d;
void setup()                    // run once, when the sketch starts
{
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("start");  // prints the sentence with ending line break 
  pinMode(7,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
 }

void loop()
{
  if(Serial.available()>0){ 
  while(Serial.available())
  { delay(10);
    char c = Serial.read();
    if (c == '#') {break;} //Exit the loop when the # is detected after the word
  d += c; //Shorthand for voice = voice + c
  }  
  if (d.length() > 0) { 
    if(d=="go forward" || d=="go straight" || d=="straight" || d=="rollout" || d=="roll out" || d=="forward" || d=="overdrive")
    {
      digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
    digitalWrite(12,HIGH);
    digitalWrite(13,LOW);
    Serial.println("Moving ahead!"); 
    }
    
    else if(d=="go back" || d=="move back" || d=="reverse" || d=="retreat" || d=="back")
    {
    digitalWrite(10,LOW);
    digitalWrite(11,HIGH);
    digitalWrite(12,LOW);
    digitalWrite(13,HIGH);
    Serial.println("Reversing!");
    }
   else if(d=="turn right" || d=="take right" || d=="take a right" || d=="right turn" || d=="dodge right")
    {
    digitalWrite(10,LOW);
    digitalWrite(11,HIGH);
    digitalWrite(12,HIGH);
    digitalWrite(13,LOW);
    }
   else if(d=="turn left" || d=="take left" || d=="take a left" || d=="left turn" || d=="dodge left")
    {
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);
    digitalWrite(13,HIGH);
    }
   else if(d=="enough" || d=="stay there" || d=="stop" || d=="take a break")
    {
    digitalWrite(10,HIGH);
    digitalWrite(11,HIGH);
    digitalWrite(12,HIGH);
    digitalWrite(13,HIGH);
  }
  else if(d=="its dark here" || d=="lights on" || d=="where is your light")
 {
  digitalWrite(7,HIGH);
 }
  else if(d=="lights off" || d=="too bright")
 {
  digitalWrite(7,LOW);
 }

 else if(d=="what is your name" || d=="whats your name")
 {
  Serial.println("My name is Alex, Your name please?");
 }
 else if(d=="good morning" || d=="good morning Alex" || d=="good morning alex")
 {
  Serial.println("Very good morning! What's up?");
 }
 else if(d=="hey Alex" || d=="Alex, are you here?")
 {
  Serial.println("Hey dude!");
 }
 else if(d=="whats up" || d=="whatsapp")
 {
  Serial.println("Nothing much. You?");
 }
 else if(d=="how are you")
 {
  Serial.println("I'm fine. You?");
 }
  else if(d=="what is one plus two" || d=="what is 1+2")
 {
  Serial.println("It's 3");
 }
  else if(d=="say hi to sir")
  {
    Serial.println("Hello sir!");
  }
  else if(d=="say hi to madame" || d=="say hi to maam" || d=="say hi to mom")
  {
    Serial.println("Hello Ma'am!");
  }
 else
 {
  Serial.println("You didn't teach me this!");
 }
 
d="";}
}
}
