#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <WiFi.h>

// Configuración del sensor DHT
#define DHTPIN 15       // Pin GPIO conectado al DHT22
#define DHTTYPE DHT22  // Tipo de sensor DHT
DHT dht(DHTPIN, DHTTYPE);

// Configuración de la red Wi-Fi
const char* ssid = "ESBACHA";
const char* password = "29349218E";

void setup() {
  // Inicializa el puerto serial
  Serial.begin(115200);

  // Inicializa el sensor DHT
  Serial.println("Inicializando sensor DHT...");
  dht.begin();

  // Conexión a Wi-Fi
  Serial.println("Conectando a Wi-Fi...");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nConectado a Wi-Fi!");
  Serial.print("Dirección IP: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Lee los valores de temperatura y humedad
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Verifica si hubo errores al leer el sensor
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Error leyendo del sensor DHT!");
    delay(2000); // Espera antes de reintentar
    return;
  }

  // Muestra los datos en el monitor serial
  Serial.print("Temperatura: ");
  Serial.print(temperature);
  Serial.println(" °C");
  
  Serial.print("Humedad: ");
  Serial.print(humidity);
  Serial.println(" %");

  delay(2000); // Lee los datos cada 2 segundos
}
