# Firmware for gps-tag-lora-addon
This repository includes the specification for and the firmware implementing the given functionality. In the first instance it is designed to talk to an external GPS tag and perform the communication.

# Specification
 * Implements LoraWAN connectivty with minimal set of features:
  * 868 EU band channels
  * ABP
  * ACK data upon request
  * set SF
  * set transmit port
 * Implements communication to the GPS tag
  * Acquires the last GPS position every X minutes (configurable)
  * Stores one location an hour in a buffer, 100 last locations, transmits upon request
  * Enables BLE upon request/command
 * Implements remote config and command
  * Configure reporting interval via Lora
  * Configure SF, TX power and other parameters
  * Process commands:
   * Retrieve position log
   * Turn on BLE
   * Turn on RF beacon
  * Configure GPS tracker parameters
   * TBD
