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

## LoRaWAN stack selection
The stack slection is important to optimize the performance of the tag. Long-term goal is to use a Semtech provided Basic MAC modem firmware implementing the full stack with advanced features, however prior to that an intermediate solution is required. Stack selection is subject to LoRa modem SX127x or SX126x, the latter bein newer and not yet very commonly supported, however preferable for our use-case.
