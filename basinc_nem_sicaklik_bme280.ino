#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME280 bme;

void setup() {
	Serial.begin(9600);

	if (!bme.begin(0x76)) {
		Serial.println("BME280 SENSÖRÜ BULUNAMADI, BAĞLANTIYI KONTROL EDİNİZ! 3.3V kullanmayı unutmayın**");
		while (1);
	}
}

void loop() {
	Serial.print("Sıcaklık = ");
	Serial.print(bme.readTemperature());
	Serial.println("*C");

	Serial.print("Basınç = ");
	Serial.print(bme.readPressure() / 100.0F);
	Serial.println("hPa");

	Serial.print("İrtifa = ");
	Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
	Serial.println("m");

	Serial.print("Nem = ");
	Serial.print(bme.readHumidity());
	Serial.println("%");

	Serial.println();
	delay(1000);
}