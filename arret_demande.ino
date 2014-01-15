#include <Process.h>
#include <Bridge.h>

const int ledPin = 13; 

void setup() {
  Bridge.begin();   // Initialize the Bridge
}

void loop() {
  Process p;
  // This command line runs the WifiStatus script, (/usr/bin/pretty-wifi-info.lua), then 
  // sends the result to the grep command to look for a line containing the word
  // "Signal:"  the result is passed to this sketch:
  p.runShellCommand("/usr/bin/curl http://mathemagie.net/projects/arret_demande/get_data_bus.phpp");

  // do nothing until the process finishes, so you get the whole output:
  while(p.running());  

  // Read command output. runShellCommand() should have passed "Signal: xx&":
  while (p.available()) {
    int result = p.parseInt();          // look for an integer
    if (result == 1) {
      digitalWrite(ledPin, HIGH);
      delay(250);
      digitalWrite(ledPin, LOW);
      delay(250);
      digitalWrite(ledPin, HIGH);
       delay(250);
      digitalWrite(ledPin, LOW);
    }else {
      digitalWrite(ledPin, LOW);
    }
  
    
  } 
  delay(1000);  // wait 5 seconds before you do it again
}
