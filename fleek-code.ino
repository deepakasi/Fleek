
const int button1Pin = 2;
const int button2Pin = 3;
const int button3Pin = 4;
const int button4Pin = 5;
const int button5Pin = 6;
const int buzzerPin = 9;
const int songLength = 18;
int x;

char notes[] = "cdfda ag cdfdg gf "; // a space represents a rest
char notes1[] = "cd ag cd gf ";

int beats[] = {1,1,1,1,1,1,4,4,2,1,1,1,1,1,1,4,4,2};

int tempo = 10;
//int tempo =150;


void setup() 
{
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  pinMode(button3Pin, INPUT);
  pinMode(button4Pin, INPUT);
  pinMode(button5Pin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}


void loop() 
{
  int button1State;
  int button2State;
  int button3State;
  int button4State;
  int button5State;
  button1State = digitalRead(button1Pin);
  button2State = digitalRead(button2Pin);
  button3State = digitalRead(button3Pin);
  button4State = digitalRead(button4Pin);
  button5State = digitalRead(button5Pin);
  int i, duration;
  if ((button1State == LOW)||(button5State == LOW)||(button4State == LOW))// if we're pushing button 1 OR button 2
  {
  for (i = 0; i < songLength; i++) // step through the song arrays
  {
    duration = beats[i] * tempo;  // length of note/rest in ms
    
    if (notes[i] == ' ')          // is this a rest? 
    {
      delay(duration);            // then pause for a moment
    }
    else                          // otherwise, play the note
    {
      tone(buzzerPin, frequency(notes[i]), duration);
      delay(duration);            // wait for tone to finish
    }
    delay(tempo/10);              // brief pause between notes
  }
  }
    if ((button2State == LOW) || (button3State == LOW))// if we're pushing button 1 OR button 2
  {
  for (i = 0; i < songLength; i++) // step through the song arrays
  {
    duration = beats[i] * tempo;  // length of note/rest in ms
    
    if (notes1[i] == ' ')          // is this a rest? 
    {
      delay(duration);            // then pause for a moment
    }
    else                          // otherwise, play the note
    {
      tone(buzzerPin, frequency(notes1[i]), duration);
      delay(duration);            // wait for tone to finish
    }
    delay(tempo/10);              // brief pause between notes
  }
  }
  
  x=analogRead(2);
  Serial.println(x);
  if (x<=50)
  {
    digitalWrite(13, LOW); 
  }
  if (x>=50)
   {
    digitalWrite(13, HIGH); 
  }                                   
}


int frequency(char note) 
{
  // This function takes a note character (a-g), and returns the
  // corresponding frequency in Hz for the tone() function.
  
  int i;
  const int numNotes = 8;  // number of notes we're storing
  
  // The following arrays hold the note characters and their
  // corresponding frequencies. The last "C" note is uppercase
  // to separate it from the first lowercase "c". If you want to
  // add more notes, you'll need to use unique characters.

  // For the "char" (character) type, we put single characters
  // in single quotes.

  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int frequencies[] = {262, 294, 330, 349, 392, 440, 494, 523};
  
  // Now we'll search through the letters in the array, and if
  // we find it, we'll return the frequency for that note.
  
  for (i = 0; i < numNotes; i++)  // Step through the notes
  {
    if (names[i] == note)         // Is this the one?
    {
      return(frequencies[i]);     // Yes! Return the frequency
    }
  }
  return(0);  // We looked through everything and didn't find it,
}

