/*#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>

#define TFT_CS    5   // Pin D5
#define TFT_DC    2   // Pin D2
#define TFT_RST   4   // Pin D4

// Initializam ecranul
Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("--- START TEST ECRAN ---");

  // Resetare manuala prin pin
  pinMode(TFT_RST, OUTPUT);
  digitalWrite(TFT_RST, LOW);
  delay(100);
  digitalWrite(TFT_RST, HIGH);
  delay(100);

  // Incearca varianta de init pentru 240x320
  Serial.println("Initializare ecran...");
  tft.init(240, 320); 
  
  // Daca ecranul e tot negru, uneori ajuta setarea modului SPI
  // tft.setSPISpeed(40000000); // 40MHz

  tft.setRotation(1);
  tft.fillScreen(ST77XX_BLUE); // Ar trebui sa se faca albastru instant
  
  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(3);
  tft.setCursor(20, 100);
  tft.println("Salut!");
  
  Serial.println("Setup finalizat. Vezi ceva albastru?");
}

void loop() {
  // Blink pe Serial ca sa stim ca placa merge
  Serial.println("Codul ruleaza...");
  delay(2000);
}
*/
/*#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  // Inițializare display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (true); // Oprește dacă display-ul nu pornește
  }

  display.clearDisplay();

  // Fundal "frumos" – linii decorative
  for (int i = 0; i < SCREEN_WIDTH; i += 4) {
    display.drawLine(i, 0, i, SCREEN_HEIGHT, SSD1306_WHITE);
  }

  // Text "Aer curat"
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(20, 20);
  display.println("Aer");
  display.setCursor(20, 40);
  display.println("curat");

  // Frunză verde stilizată (desenată manual)
  drawLeaf(100, 5);

  display.display();
}

void loop() {
  // Nimic în loop
}

// Funcție care desenează o frunză
void drawLeaf(int x, int y) {
  display.drawEllipse(x, y + 10, 6, 10, SSD1306_WHITE); // corp frunză
  display.drawLine(x, y + 20, x, y + 28, SSD1306_WHITE); // codiță

}
*/
/*#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  // Inițializare display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3D)) {
    while (true); // Oprește dacă display-ul nu pornește
  }

  display.clearDisplay();

  // Fundal "frumos" – linii decorative
  for (int i = 0; i < SCREEN_WIDTH; i += 4) {
    display.drawLine(i, 0, i, SCREEN_HEIGHT, SSD1306_WHITE);
  }

  // Text "Aer curat"
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(20, 20);
  display.println("Aer");
  display.setCursor(20, 40);
  display.println("curat");

  // Frunză verde stilizată (desenată manual)
  drawLeaf(100, 5);

  display.display();
}

void loop() {
  // Nimic în loop
}

// Funcție care desenează o frunză
void drawLeaf(int x, int y) {
  display.drawEllipse(x, y + 10, 6, 10, SSD1306_WHITE); // corp frunză
  display.drawLine(x, y + 20, x, y + 28, SSD1306_WHITE); // codiță
}
*/


/*#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>

// PINI TFT (modifică dacă e nevoie)
#define TFT_CS   5
#define TFT_DC   2
#define TFT_RST  4

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

void setup() {
  // Inițializare TFT
  tft.init(240, 320);      // schimbă la 240,320 dacă e cazul
  tft.setRotation(0);

  // Fundal frumos (albastru deschis)
  tft.fillScreen(ST77XX_CYAN);

  // Text "Aer curat"
  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(3);
  tft.setCursor(40, 90);
  tft.println("Aer");
  tft.setCursor(30, 130);
  tft.println("curat");

  // Frunză verde (dreapta sus)
  drawLeaf(190, 30);
}

void loop() {
  // nimic
}

// Frunză stilizată
void drawLeaf(int x, int y) {
  tft.fillEllipse(x, y, 15, 25, ST77XX_GREEN);
  //tft.drawLine(x, y + 25, x, y + 45, ST77XX_DARKGREEN);
  tft.drawLine(x, y + 25, x, y + 45, ST77XX_GREEN);

}
*/

/*#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>

// PINI TFT (verifică dacă sunt corecți pentru placa ta)
#define TFT_CS   5
#define TFT_DC   2
#define TFT_RST  4

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

void drawLeaf(int x, int y);

void setup() {
  // Inițializare TFT
  tft.init(240, 320);          // dacă ai display pătrat, schimbă în 240,240
  tft.setRotation(1);

  // Curățare ecran
  tft.fillScreen(ST77XX_CYAN);

  // Text "Aer curat"
  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(5);
  tft.setCursor(40, 90);
  tft.println("Aer");
  tft.setCursor(30, 130);
  tft.println("curat");

  // Frunză verde (dreapta sus)
  drawLeaf(250, 100);
}

void loop() {
  // nimic
}

// Frunză stilizată (compatibil 100%)
void drawLeaf(int x, int y) {
  // partea stângă
  tft.fillCircle(x - 6, y, 15, ST77XX_GREEN);
  // partea dreaptă
  tft.fillCircle(x + 6, y, 15, ST77XX_GREEN);
  // codița
  tft.drawLine(x, y + 12, x, y + 35, ST77XX_GREEN);
}
*/

/* #include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>

#define TFT_CS    5
#define TFT_RST   4
#define TFT_DC    2
#define SENSOR_PIN 34 

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

int animStep = 0;
int sensorBaseline = 0;

void setup() {
  Serial.begin(115200);
  tft.init(240, 320); 
  tft.setRotation(1);
  tft.fillScreen(ST77XX_BLACK);

  // Calibrare rapidă la pornire: presupunem că aerul e curat acum
  tft.setCursor(20, 100);
  tft.setTextColor(ST77XX_CYAN);
  tft.println("Calibrare senzor...");
  
  long sum = 0;
  for(int i=0; i<10; i++) {
    sum += analogRead(SENSOR_PIN);
    delay(100);
  }
  sensorBaseline = sum / 10; // Luăm valoarea medie a aerului curat
  tft.fillScreen(ST77XX_BLACK);
}

void loop() {
  int rawValue = analogRead(SENSOR_PIN);
  
  // Dacă rawValue e mai mic decât baseline-ul, îl actualizăm (auto-calibrare)
  if (rawValue < sensorBaseline) sensorBaseline = rawValue;

  // Calculăm poluarea față de punctul de referință
  // Dacă valoarea crește cu doar 200 unități peste baseline, ajunge la 100%
  int diff = rawValue - sensorBaseline;
  int qualityPercent = map(diff, 0, 300, 0, 100); 
  qualityPercent = constrain(qualityPercent, 0, 100);
  
  drawUI(qualityPercent, rawValue, sensorBaseline);
  playAnimation(qualityPercent);
  
  delay(50); 
}

void drawUI(int val, int raw, int base) {
  tft.setTextSize(3);
  tft.setCursor(20, 30);
  
  if (val < 15) {
    tft.setTextColor(ST77XX_GREEN, ST77XX_BLACK);
    tft.println("AER: CURAT   ");
  } else if (val < 45) {
    tft.setTextColor(ST77XX_YELLOW, ST77XX_BLACK);
    tft.println("AER: MODERAT ");
  } else {
    tft.setTextColor(ST77XX_RED, ST77XX_BLACK);
    tft.println("AER: POLUAT! ");
  }
  
  tft.setTextSize(2);
  tft.setCursor(20, 80);
  tft.setTextColor(ST77XX_WHITE, ST77XX_BLACK);
  tft.printf("Poluare: %d%%  ", val);
  
  // Info de diagnostic sub animație
  tft.setTextSize(1);
  tft.setCursor(20, 210);
  tft.setTextColor(ST77XX_CYAN, ST77XX_BLACK);
  tft.printf("Senzor acum: %d | Referinta: %d", raw, base);
}

void playAnimation(int val) {
  int centerX = 160; 
  int centerY = 165;
  int baseRadius = 35; 
  int pulse = (animStep % 12);
  
  uint16_t color = ST77XX_GREEN;
  if (val > 15) color = ST77XX_YELLOW;
  if (val > 45) color = ST77XX_RED;

  // Cercul exterior care pulsează
  tft.drawCircle(centerX, centerY, baseRadius + pulse, color);
  tft.drawCircle(centerX, centerY, baseRadius + pulse + 1, ST77XX_BLACK);
  
  // Un cerc interior fix pentru un aspect mai "tehnic"
  tft.drawCircle(centerX, centerY, baseRadius - 5, ST77XX_WHITE);
  
  animStep++;
}
*/
/*
 * PROIECT LICENȚĂ: Purificator de Aer Smart (Versiune Offline)
 * Hardware: ESP32, ST7789 TFT, 4-Pin Fan, CCS811 Sensor
 */

/* #include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_AHTX0.h>   
#include <ScioSense_ENS160.h> 

// --- PINI CONFIGURARE ---
#define TFT_CS    5
#define TFT_DC    2
#define TFT_RST   4
#define FAN_PWM   13  

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);
Adafruit_AHTX0 aht;
ScioSense_ENS160 ens160(ENS160_I2CADDR_0); 

// Variabile sistem
float temp = 22.0, hum = 50.0;
int aqi = 1, tvoc = 0, eco2 = 400;
unsigned long lastUpdate = 0;
bool dotState = false;

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);

  // Initializare Display
  tft.init(240, 320);
  tft.setRotation(1);
  tft.fillScreen(ST77XX_BLACK);
  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(2);
  tft.setCursor(20, 100);
  tft.println("Sincronizare senzori...");

  // Initializare AHT21
  if (!aht.begin()) Serial.println("AHT21 a fost gasit!");

  // Initializare ENS160 (Verificare ambele adrese)
  if (!ens160.begin()) {
    Serial.println("Incercam adresa 0x52...");
    ens160 = ScioSense_ENS160(ENS160_I2CADDR_1);
    if (!ens160.begin()) {
       tft.fillScreen(ST77XX_BLACK);
       tft.setTextColor(ST77XX_RED);
       tft.setCursor(20, 100);
       tft.println("CONEXIUNE ENS160!");
       while(1); 
    }
  }
  
  ens160.setMode(ENS160_OPMODE_STD);

  //  Configurare Ventilator (Initial Stand-by)
  ledcAttach(FAN_PWM, 25000, 8); 
  ledcWrite(FAN_PWM, 255 - 40); // Logica inversata
  
  delay(1500);
  tft.fillScreen(ST77XX_BLACK);

  // DESENARE INTERFATA STATICA (Zero Flicker) ---
  tft.drawRect(5, 5, 310, 230, ST77XX_WHITE);
  tft.setTextSize(2);
  tft.setCursor(20, 25);
  tft.setTextColor(ST77XX_CYAN);
  tft.print("CALITATE AER: ");

  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(20, 70);  tft.print("CO2: "); 
  tft.setCursor(20, 105); tft.print("TVOC: ");
  tft.setCursor(20, 140); tft.print("Temp: ");
  tft.setCursor(20, 175); tft.print("Umid: ");
  tft.setCursor(20, 210); 
  tft.setTextColor(ST77XX_YELLOW); 
  tft.print("VITEZA FAN: ");
}

void loop() {
  // Executam citirea si update-ul la fiecare 2 secunde
  if (millis() - lastUpdate > 2000) {
    
    // Citire Temperatura/Umiditate de la AHT21
    sensors_event_t humidity, temp_event;
    aht.getEvent(&humidity, &temp_event);
    temp = temp_event.temperature;
    hum = humidity.relative_humidity;

    // --- COMPENSARE MEDIU (Folosind set_envdata conform erorii tale) ---
    ens160.set_envdata(temp, hum);

    // Citire date de la ENS160
    if (ens160.available()) {
      ens160.measure(true); 
      aqi = ens160.getAQI();
      tvoc = ens160.getTVOC();
      eco2 = ens160.geteCO2();
    }

    // CONTROL VENTILATOR (Logica Inversata)
    // Daca AQI > 1, turam motorul. Altfel, viteza de Stand-by (40).
    int rawPower = (aqi > 1) ? map(aqi, 2, 5, 120, 255) : 40;
    ledcWrite(FAN_PWM, 255 - rawPower);
    
    // Refresh date pe ecran
    updateDisplay();
    
    // Indicator vizual (mic punct in colt care clipeste)
    dotState = !dotState;
    tft.fillCircle(300, 15, 3, dotState ? ST77XX_GREEN : ST77XX_BLACK);

    lastUpdate = millis();
  }
}

void updateDisplay() {
  // 1. Status AQI
  uint16_t statusColor = ST77XX_GREEN;
  String statusTxt = "";
  if (aqi == 1)      { statusColor = ST77XX_GREEN;  statusTxt = "EXCELENTA "; }
  else if (aqi == 2) { statusColor = 0xAFE5;        statusTxt = "BUNA      "; }
  else if (aqi == 3) { statusColor = ST77XX_YELLOW; statusTxt = "MODERATA  "; }
  else if (aqi == 4) { statusColor = ST77XX_ORANGE; statusTxt = "POLUATA   "; }
  else               { statusColor = ST77XX_RED;    statusTxt = "CRITICA   "; }
  
  tft.setCursor(180, 25);
  tft.setTextColor(statusColor, ST77XX_BLACK);
  tft.print(statusTxt);

  // 2. Date Senzori (Suprascriere pe fundal negru)
  tft.setTextColor(ST77XX_WHITE, ST77XX_BLACK);
  tft.setCursor(80, 70);   tft.print(eco2); tft.print(" ppm   ");
  tft.setCursor(90, 105);  tft.print(tvoc); tft.print(" ppb   ");
  tft.setCursor(90, 140);  tft.print(temp, 1); tft.print(" C  ");
  tft.setCursor(90, 175);  tft.print(hum, 1); tft.print(" %  ");

  // 3. Status Ventilator
  tft.setCursor(160, 210);
  if (aqi > 1) {
    tft.setTextColor(ST77XX_YELLOW, ST77XX_BLACK);
    int percent = map(aqi, 2, 5, 45, 100);
    tft.print(percent); tft.print("%       "); 
  } else {
    tft.setTextColor(ST77XX_GREEN, ST77XX_BLACK);
    tft.print("STAND-BY ");
  }
}
*/
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_AHTX0.h>   
#include <ScioSense_ENS160.h> 
#include <WiFi.h>
#include <HTTPClient.h> 

// --- CONFIGURARE WIFI ---
const char* ssid     = "Caius";      
const char* password = "Lambo2000";    

// Adresa Backend-ului (Laptopul tau)
const char* serverUrl = "http://172.20.10.11:3000/api/data";

// --- PINI CONFIGURARE ---
#define TFT_CS    5
#define TFT_DC    2
#define TFT_RST   4
#define FAN_PWM   13  

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);
Adafruit_AHTX0 aht;
ScioSense_ENS160 ens160(ENS160_I2CADDR_0); 

// Variabile sistem
float temp = 22.0, hum = 50.0;
int aqi_logic = 1; 
int tvoc = 0, eco2 = 400;
int currentRawPower = 5; 
unsigned long lastUpdate = 0;
bool dotState = false;

String regimFan = "auto"; // Modul curent primit de la server (auto, turbo, stop)

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);

  tft.init(240, 320);
  tft.setRotation(1);
  tft.fillScreen(ST77XX_BLACK);
  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(2);
  tft.setCursor(20, 50);
  tft.println("Conectare WiFi...");

  WiFi.begin(ssid, password);
  int retry = 0;
  while (WiFi.status() != WL_CONNECTED && retry < 15) {
    delay(500);
    tft.print(".");
    retry++;
  }

  tft.fillScreen(ST77XX_BLACK);

  if (!aht.begin()) Serial.println("AHT21 negasit");
  if (!ens160.begin()) {
    ens160 = ScioSense_ENS160(ENS160_I2CADDR_1);
    if (!ens160.begin()) {
      tft.setCursor(20, 100); tft.setTextColor(ST77XX_RED);
      tft.println("EROARE SENZOR AER!"); while(1);
    }
  }
  ens160.setMode(ENS160_OPMODE_STD);

  ledcAttach(FAN_PWM, 25000, 8); 

  tft.drawRect(5, 5, 310, 230, ST77XX_WHITE);
  tft.setTextSize(2);
  tft.setCursor(20, 25); tft.setTextColor(ST77XX_CYAN); tft.print("CALITATE AER: ");
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(20, 70);  tft.print("CO2: "); 
  tft.setCursor(20, 105); tft.print("TVOC: ");
  tft.setCursor(20, 140); tft.print("Temp: ");
  tft.setCursor(20, 175); tft.print("Umid: ");
  tft.setCursor(20, 210); tft.setTextColor(ST77XX_YELLOW); tft.print("VITEZA FAN: ");
}

void loop() {
  if (millis() - lastUpdate > 2000) {
    
    //Citire senzori
    sensors_event_t humidity, temp_event;
    aht.getEvent(&humidity, &temp_event);
    temp = temp_event.temperature;
    hum = humidity.relative_humidity;

    ens160.set_envdata(temp, hum);
    if (ens160.available()) {
      ens160.measure(true); 
      tvoc = ens160.getTVOC();
      eco2 = ens160.geteCO2();
    }

    //COMUNICARE REȚEA (Trimitem date, primim comanda)
    if(WiFi.status() == WL_CONNECTED) {
      HTTPClient http;
      http.begin(serverUrl);
      http.addHeader("Content-Type", "application/json");

      String json = "{\"temp\":" + String(temp) + 
                    ",\"hum\":" + String(hum) + 
                    ",\"co2\":" + String(eco2) + 
                    ",\"tvoc\":" + String(tvoc) + 
                    ",\"fan\":" + String(map(currentRawPower, 0, 255, 0, 100)) + "}";
      
      int httpResponseCode = http.POST(json);
      
      if(httpResponseCode == 200) {
        String response = http.getString();
        Serial.print("Raspuns de la server: "); Serial.println(response);
        
        // Extragere sigură a comenzii din JSON-ul {"cmd":"valoare"}
        if (response.indexOf("\"cmd\":\"turbo\"") != -1) {
          regimFan = "turbo";
        } else if (response.indexOf("\"cmd\":\"stop\"") != -1) {
          regimFan = "stop";
        } else {
          regimFan = "auto";
        }
        Serial.print("Regim Fan activat: "); Serial.println(regimFan);
      } else {
        Serial.print("HTTP Error: "); Serial.println(httpResponseCode);
      }
      http.end();
    }

    // --- 3. LOGICA CONTROL VENTILATOR ---
    if (regimFan == "turbo") {
      currentRawPower = 255; // Maxim
      aqi_logic = 5;
    } 
    else if (regimFan == "stop") {
      currentRawPower = 0;   // Oprit complet
      aqi_logic = 1;
    } 
    else { // Modul AUTO (Proporțional pe baza senzorilor)
      int pCO2 = map(constrain(eco2, 450, 1200), 450, 1200, 5, 255);
      int pTVOC = map(constrain(tvoc, 50, 400), 50, 400, 5, 255);
      currentRawPower = max(pCO2, pTVOC);

      if (currentRawPower <= 10) aqi_logic = 1;
      else if (currentRawPower < 80) aqi_logic = 2;
      else if (currentRawPower < 150) aqi_logic = 3;
      else if (currentRawPower < 220) aqi_logic = 4;
      else aqi_logic = 5;
    }

    // Aplicăm puterea fizică (Logica Inversată)
    ledcWrite(FAN_PWM, 255 - currentRawPower);

    updateDisplay();
    
    dotState = !dotState;
    tft.fillCircle(300, 15, 3, dotState ? ST77XX_GREEN : ST77XX_BLACK);

    lastUpdate = millis();
  }
}

void updateDisplay() {
  uint16_t statusColor = ST77XX_GREEN;
  String statusTxt = "";
  
  if (regimFan == "turbo") {
    statusColor = ST77XX_RED;
    statusTxt = "TURBO FORAT";
  } else if (regimFan == "stop") {
    statusColor = ST77XX_WHITE;
    statusTxt = "OPRIT MAN.";
  } else {
    switch(aqi_logic) {
      case 1: statusColor = ST77XX_GREEN;  statusTxt = "EXCELENTA "; break;
      case 2: statusColor = 0xAFE5;        statusTxt = "BUNA      "; break;
      case 3: statusColor = ST77XX_YELLOW; statusTxt = "MODERATA  "; break;
      case 4: statusColor = ST77XX_ORANGE; statusTxt = "POLUATA   "; break;
      case 5: statusColor = ST77XX_RED;    statusTxt = "CRITICA   "; break;
    }
  }
  
  tft.setCursor(180, 25); tft.setTextColor(statusColor, ST77XX_BLACK); tft.print(statusTxt);
  tft.setTextColor(ST77XX_WHITE, ST77XX_BLACK);
  tft.setCursor(80, 70);   tft.print(eco2); tft.print(" ppm   ");
  tft.setCursor(90, 105);  tft.print(tvoc); tft.print(" ppb   ");
  tft.setCursor(90, 140);  tft.print(temp, 1); tft.print(" C  ");
  tft.setCursor(90, 175);  tft.print(hum, 1); tft.print(" %  ");
  
  tft.setCursor(160, 210);
  if (currentRawPower > 10) {
    tft.setTextColor(ST77XX_YELLOW, ST77XX_BLACK);
    tft.print(map(currentRawPower, 0, 255, 0, 100)); tft.print("%       "); 
  } else {
    tft.setTextColor(ST77XX_GREEN, ST77XX_BLACK);
    tft.print("STAND-BY ");
  }
}