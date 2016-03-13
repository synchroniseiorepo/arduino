[Synchronise](https://www.synchronise.io)
--------------
Disclaimer: This is a work in progress. The library will be complete in a few days, please be patient.

The Arduino Yùn client allows you to communicate with Synchronise in a very simple and elegant way.
The library communicates with our servers using the bridge library introduced specifically for the Arduino Yùn. The architecture of the cakks is different and does not rely on a callback mechanism like in our javascript library. Instead it let's you call components and workflows one after the other.

----------


### Setup

You first need to download our library and integrate it in your project.
[arduino.synchronise.io/synchronise.1.0.zip](https://arduino.synchronise.io/synchronise.1.0.zip)
----------
### Import the library in the Arduino IDE
![Find your public key](https://images.synchronise.io/importArduinoLibrary.png)
----------


### Init
Make sure you have inluded our library at the beginning of your sketch.
```
#include <Synchronise.h>
```

To get started with the Arduino Yùn library you first need to initialise it. This is achieved by creating a new client and giving it your Public Key. We have pre-filled it with your own Public Key so you can just copy paste it at the beginning of your sketch

```
#include <Synchronise.h>
Synchronise SClient("[YOUR PUBLIC KEY]");

void setup(){
...
```    

You can also find your Public Key at synchronise.io/connect

----------

### Component
There are two scenarios for calling a Component from an Arduino.
* Simply triggering an event on a web service. This is just a simple call.
* Collecting or storing information coming from sensors on your Arduino. This is a call that requires to send Inputs.

#### Run
Call without any parameters or return value. Simplest version

**Example:**
```
void loop(){
    client.componentRun("THE ID OF THE COMPONENT TO CALL");
}
```

Call with inputs and outputs. The function componentRun returns an object of type SynchroniseOutputs which allow you to read data in simpler way.

**Example:**
```
void loop(){
   // Creates an input object to send data to the server
   SynchroniseInputs inputs;
   inputs.setInput("my_data", 1);
   inputs.setInput("another", "value");

   SynchroniseOutputs outputs = client.componentRun("THE ID OF THE COMPONENT TO CALL", &inputs);

   // You will need to specify the type of data you want to collect
   // Bellow are some examples
   // my_data is the key of the data you want to read
   Serial.println(outputs.getBool("my_data"));
   // another os the key of the data you want to read
   Serial.println(outputs.getConstChar("another"));
}
```

#### Full reference
* Synchronise.cpp

```
Synchronise(const char* public_key);
SynchroniseOutputs componentRun(const char* component_id, SynchroniseInputs* inputs);
SynchroniseOutputs componentRun(const char* component_id);
```

* SynchroniseInputs.cpp

```
SynchroniseInputs();
void setInput(const char* name, char value);
void setInput(const char* name, char* value);
void setInput(const char* name, const char* value);
void setInput(const char* name, int value);
void setInput(const char* name, long value);
void setInput(const char* name, short value);
void setInput(const char* name, float value);
void setInput(const char* name, double value);
void setInput(const char* name, bool value);
void toString(); // Displays the inputs in the Serial
```

* SynchroniseInputs.cpp
```
bool getBool(const char * key);
char getChar(const char * key);
long getLong(const char * key);
int getInt(const char * key);
short getShort(const char * key);
float getFloat(const char * key);
double getDouble(const char * key);
const char* getConstChar(const char * key);
```

The JSON coming from the server is handled by the library [ArduinoJson](https://github.com/bblanchon/ArduinoJson)
