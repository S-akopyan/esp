#include <Arduino.h>

// Подключение библиотеки ESPHome
#include "esphome.h"

class FlashingLedComponent : public Component, public LightOutput {
 public:
  void setup() override {
    // Инициализация пина светодиода
    pinMode(LED_BUILTIN, OUTPUT);
  }

  void write_state(LightState *state) override {
    // Мигание светодиода
    if (state->state) {
      digitalWrite(LED_BUILTIN, HIGH); // Включение светодиода
      delay(500);
      digitalWrite(LED_BUILTIN, LOW); // Выключение светодиода
      delay(500);
    }
  }
};

// Создание экземпляра компонента
FlashingLedComponent *flashing_led = new FlashingLedComponent();

// Пользовательская функция для запуска
void setup() {
  flashing_led->setup();
}

// Пользовательская функция для обновления
void loop() {
}

