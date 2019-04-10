#include <LibLacuna.h>

// Install https://github.com/IRNAS/ArduinoCore-stm32l0 board support

/*static byte networkKey[] = { 
    // TODO: Replace with your network key
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
static byte appKey[] = {
    // TODO: Replace with your application key
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
//TODO: Replace with your device address
static byte deviceAddress[] = { 0x00, 0x00, 0x00, 0x00 };
*/

// Changes from the basic example:
// Added LED pins
// Debug is via Serial1
// Configured SX pins

#define LED_1 PB7
#define LED_2 PB10

static lsLoraWANParams loraWANParams;

static byte payload[] = "Lacuna";

void setup() {
  Serial1.begin(115200);
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  // LED is active at LOW
  digitalWrite(LED_1, LOW);
  digitalWrite(LED_2, LOW);
  delay(500);
  Serial1.println("Initializing");
  lsCreateDefaultLoraWANParams(&loraWANParams, networkKey, appKey, deviceAddress);


  lsSX126xConfig cfg = {
      nssPin: PA4,
      resetPin: PA15,                                                               
      antennaSwitchPin: PA1,
      busyPin: PA0,
      osc: lsSX126xOscTCXO,
      type: lsSX126xTypeSX1262
  };
  int result = lsInitSX126x(&cfg);
  if(result) Serial1.println(lsErrorToString(result));
  digitalWrite(LED_1, HIGH);
  digitalWrite(LED_2, HIGH);
}

void loop() {
  digitalWrite(LED_1, LOW);
	lsLoraTxParams txParams;
  lsCreateDefaultLoraTxParams(&txParams);
  txParams.spreadingFactor=lsLoraSpreadingFactor_9;
	Serial1.println("Sending Lora message");
	int result = lsSendLoraWAN(&loraWANParams, &txParams, (byte *)payload, sizeof payload-1);
	Serial1.println(lsErrorToString(result));
	loraWANParams.framecounter++;
  digitalWrite(LED_1, HIGH);
	delay(5000);

  digitalWrite(LED_2, LOW);
	lsLoraETxParams etxParams;
  lsCreateDefaultLoraETxParams(&etxParams);
	Serial1.println("Sending Lora-E message");
	result = lsSendLoraEWAN(&loraWANParams, &etxParams, (byte *)payload, sizeof payload-1);
	Serial1.println(lsErrorToString(result));
	loraWANParams.framecounter++;
 digitalWrite(LED_2, HIGH);
	delay(5000);
}
