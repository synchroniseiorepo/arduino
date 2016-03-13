/* Synchronise.cpp - Client library to communicate with the REST API of synchronise.io
   Created by Thibaut Rey, March 6, 2016.*/
#include "Synchronise.h"
#define BUFFER_SIZE 500

const char *server = "api.synchronise.io"; /* ADDRESS OF THE SERVER */

Synchronise::Synchronise(const char* public_key){
    _public_key = public_key;
}

SynchroniseOutputs Synchronise::sendRequest(const char*id_element, const char* type_request, SynchroniseInputs* inputs, SuccessCallback *success, ErrorCallback *error){
    char buffer[BUFFER_SIZE];
    Process proc;
    // Parameters CURL
    proc.begin("curl"); proc.addParameter("-k"); proc.addParameter("-X"); proc.addParameter("POST"); proc.addParameter("-H");
    // Headers
    proc.addParameter("Content-Type: application/json"); proc.addParameter("-H"); sprintf(buffer, "x-synchronise-public-key: %s", _public_key); proc.addParameter(buffer);

    // Prepare the inputs
    /* Set the component ID            */ /* Set the client as an arduino  */
    inputs->setInput("id", id_element); inputs->setInput("S_C", "arduino"); proc.addParameter("-d");
    // Formats the inputs and stores them in the request
    inputs->_root.printTo(buffer, BUFFER_SIZE); proc.addParameter(buffer);

    // Formats the url of the request
    sprintf(buffer, "https://%s/%s/run", server, type_request); proc.addParameter(buffer);
    proc.run(); // RUN

    while (!proc.available()) { delay(50); } // Wait for request to be done
    long timestamp = millis();

    // Empty the buffer in order to reuse it for storing the callbacks data
    memset(buffer, 0, sizeof(buffer));
    int i = 0; // Position
    bool request_succeeded = false;
    bool buffer_too_small = false;
    while (proc.available()) {
        char c = proc.read();
        if(i == 0){ // First parameter
            request_succeeded = (c == '1');
        }
        if(i < BUFFER_SIZE){ // Avoid writing out of the BUFFER
            buffer[i] = c;
        }else{
            buffer_too_small = true;
            request_succeeded = false;
        }
        i++;
    }

    Serial.println(buffer);
    if(request_succeeded){
        SynchroniseOutputs results = SynchroniseOutputs(buffer, BUFFER_SIZE);
        results.setBool("status", true);
        return results;
    }else{
        if(buffer_too_small){
            SynchroniseOutputs results = SynchroniseOutputs("{\"err\":\"Buffer is too small. \"}", BUFFER_SIZE);
            results.setBool("status", false);
            return results;
        }else{
            SynchroniseOutputs results = SynchroniseOutputs(buffer, BUFFER_SIZE);
            results.setBool("status", false);
            return results;
        }
    }
}

// Component run without inputs and without any callbacks
SynchroniseOutputs Synchronise::componentRun(const char* component_id){
    SynchroniseInputs inputs; // Create empty inputs
    return this->sendRequest(&*component_id, "component", &inputs, NULL, NULL);
}

SynchroniseOutputs  Synchronise::componentRun(const char* component_id, SynchroniseInputs* inputs){
    return this->sendRequest(&*component_id, "component", inputs, NULL, NULL);
}
