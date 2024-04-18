#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>

const char* ssid = "EuMesmoRhuan";
const char* password = "fernandesmontes";
String resposta = "bab";
String serverName = "http://api.open-notify.org/iss-now.json";
JsonDocument doc;


void setup() {
  Serial.begin(9600);
  WiFi.begin (ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
 
  Serial.print("Usar essa URL : ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
}

void loop ()
{
  if (WiFi.status() == WL_CONNECTED) {
    // Consulta posição atual
    HTTPClient http;
    WiFiClient client;
    http.begin(client, serverName.c_str());
    int httpCode = http.GET();
    if (httpCode > 0) {
      resposta = http.getString();
      Serial.println(resposta);
    }else {
      Serial.print("Error code: ");
    }
    Serial.println(httpCode);
    http.end();
    DeserializationError error = deserializeJson(doc, resposta);
    if (error) {
      Serial.print(F("deserializeJson() failed: "));
      Serial.println(error.c_str());
      return;
    }

    // Verifica se o JSON é um objeto
    if (doc.is<JsonObject>()) {
      // Obtém uma referência para o objeto JSON
      JsonObject obj = doc.as<JsonObject>();

      // Percorre todos os pares chave-valor no objeto JSON
      for (JsonPair kvp : obj) {
        // 'kvp.key()' contém a chave
        // 'kvp.value()' contém o valor associado à chave
        String chave = kvp.key().c_str();
        
        // Verifica se o valor associado à chave é uma String
        if (kvp.value().is<const char*>()) {
          String valor = kvp.value().as<String>();
          
          // Faça o que você precisa com a chave e o valor
          Serial.print("Chave: ");
          Serial.print(chave);
          Serial.print(", Valor: ");
          Serial.println(valor);
        } else {
          Serial.print("O valor associado à chave ");
          Serial.print(chave);
          Serial.println(" não é uma string.");
        }
      }
    } else {
      Serial.println("O JSON não é um objeto");
    }


    // // Extract the values
    // const char* sensor = doc["message"];
    // long time = doc["timestamp"];
    // double latitude = doc["iss_position"]["longitude"];
    // double longitude = doc["iss_position"]["latitude"];

    // // Print the values
    // Serial.println(sensor);
    // Serial.println(time);
    // Serial.println(latitude, 6);
    // Serial.println(longitude, 6);
  }
 
  // 30 segundos entre as consultas
  delay (1000);
}
