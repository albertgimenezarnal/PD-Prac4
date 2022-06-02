#include <Arduino.h>

int i,c;
const int led1 = 2;
const int led2 = 21;
void toggleLED(void * parameter);
void ledVerde(void * parameter);
void setup(){
  Serial.begin(115200);
  Serial.println("Inicio");
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  xTaskCreate(
    toggleLED,    // Function that should be called
    "Toggle LED",   // Name of the task (for debugging)
    1000,            // Stack size (bytes)
    NULL,            // Parameter to pass
    1,               // Task priority
    NULL             // Task handle
  );
  xTaskCreatePinnedToCore(
      ledVerde,
      "ledVerde",
      1000,
      NULL,
      1,
      NULL,
      1
  );
}
  void toggleLED(void * parameter){
      Serial.println("prueba0");
    for(;;){ // infinite loop

      // Turn the LED on
      digitalWrite(led1, HIGH);

      // Pause the task for 500ms
      digitalWrite(led1, HIGH);

      // Turn the LED off
      digitalWrite(led1, LOW);

      // Pause the task again for 500ms
      vTaskDelay(500 / portTICK_PERIOD_MS);
    }
  }
void ledVerde(void * parameter){
    Serial.println("prueba");
    for(i=0;i<10;i++){
        Serial.println(i);
        for(c=0;c<=i;c++){
            digitalWrite(led2, HIGH);
            vTaskDelay(500 / portTICK_PERIOD_MS);
            digitalWrite(led2, LOW);
            Serial.println(c);
        }
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
    vTaskDelete(NULL);
}
void loop(){}