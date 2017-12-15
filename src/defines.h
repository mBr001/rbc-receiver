#define DEBUG true

#if DEBUG
#define print(var) Serial.print(var)
#else
#define print(var)
#endif

#define NODEID 1
#define NETWORKID 100
#define GATEWAYID 2
#define FREQUENCY RF69_868MHZ  // Match this with the version of your Moteino! (others: RF69_433MHZ, RF69_868MHZ)
#define KEY "sampleEncryptKey" // has to be same 16 characters/bytes on all nodes, not more not less!
#define LED 13
#define SERIAL_BAUD 57600
#define ACK_TIME 50 // # of ms to wait for an ack
#define PROMISCUOUS_MODE false // set to 'true' to sniff all packets on the same network