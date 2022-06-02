#include <Arduino.h>
int i,c;
TaskHandle_t * tarea1handler = NULL;
TaskHandle_t * tarea2handler = NULL;
const int led1 = 2;
const int led2 = 21;
void tarea1(void * parameter);
void tarea2(void * parameter);
void otainit(void * parameter);
void setup(){
  Serial.begin(115200);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  xTaskCreate(
    tarea1,    
    "Toggle LED",   
    1000,            
    NULL,            
    1,   
    tarea1handler             
  );
  xTaskCreate(
      tarea2,
      "ledVerde",
      1000,
      NULL,
      1,
      tarea2handler
  );
  xTaskCreate(
      otainit,
      "otainit",
      4000,
      NULL,
      1,
      tarea2handler
  );
}
void tarea1(void * parameter){
    Serial.println("tarea1");
      //if(tarea2handler != NULL) {
      //vTaskDelete(tarea2handler);
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
    // }
  }
void tarea2(void * parameter){
  Serial.println("tarea2");
      for(;;){ // infinite loop
        // Turn the LED on
        digitalWrite(led2, HIGH);

        // Pause the task for 500ms
        digitalWrite(led2, HIGH);

        // Turn the LED off
        digitalWrite(led2, LOW);

        // Pause the task again for 500ms
        vTaskDelay(500 / portTICK_PERIOD_MS);
      }
    }

void loop(){}