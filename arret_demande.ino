#include <Process.h>
#include <Bridge.h>
#include <Console.h>

const int ledPin = 6; 

void setup() {
  Bridge.begin();   // Initialize the Bridge
  Console.begin(); 
  pinMode(ledPin, OUTPUT);
 
}

void loop() {
  Process p;
  p.runShellCommand("/usr/bin/curl http://mathemagie.net/projects/arret_demande/get_data_bus.php");
  Console.println("run curl command");
  
  while(p.running());  

  // Read command output. runShellCommand() should have passed "Signal: xx&":
  while (p.available()) {
    int result = p.parseInt();          // look for an integer
    if (result == 1) {
      Console.println("light on");
      digitalWrite(ledPin, HIGH);
      delay(250);
      digitalWrite(ledPin, LOW);
      delay(250);
      digitalWrite(ledPin, HIGH);
       delay(250);
      digitalWrite(ledPin, LOW);
    }
     if (result == 2) {
        digitalWrite(ledPin, HIGH);//bug in parsing process
     }
       
    if (result == 0) {
        digitalWrite(ledPin, LOW);//bug in parsing process
        Console.println("light off");
    }
  
    
  } 
  delay(1000);  // wait 5 seconds before you do it again
}
