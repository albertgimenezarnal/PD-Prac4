#include <Arduino.h>

const int led1 = 2;
void toggleLED(void * parameter);
void setup(){
  pinMode(led1, OUTPUT);
  xTaskCreate(
    toggleLED,    // Function that should be called
    "Toggle LED",   // Name of the task (for debugging)
    1000,            // Stack size (bytes)
    NULL,            // Parameter to pass
    1,               // Task priority
    NULL             // Task handle
  );
}
  void toggleLED(void * parameter){
    for(;;){ // infinite loop

      // Turn the LED on
      digitalWrite(led1, HIGH);

      // Pause the task for 500ms
      vTaskDelay(500 / portTICK_PERIOD_MS);

      // Turn the LED off
      digitalWrite(led1, LOW);

      // Pause the task again for 500ms
      vTaskDelay(500 / portTICK_PERIOD_MS);
    }
  }

void loop(){}