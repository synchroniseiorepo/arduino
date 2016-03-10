/* Synchronise.cpp - Client library to communicate with the REST API of synchronise.io
   Created by Thibaut Rey, March 6, 2016.*/
#include <Bridge.h>
#include "Synchronise.h"
#define BUFFER_SIZE 500

const char *server = "api.synchronise.io"; /* ADDRESS OF THE SERVER */

Synchronise::Synchronise(const char* public_key){
    _public_key = public_key;
}

long Synchronise::componentRun(const char* component_id, SynchroniseInputs* inputs, SuccessCallback success, ErrorCallback error){
    char buffer[BUFFER_SIZE];
    Process proc;
    // Parameters CURL
    proc.begin("curl"); proc.addParameter("-k"); proc.addParameter("-X"); proc.addParameter("POST"); proc.addParameter("-H");
    // Headers
    proc.addParameter("Content-Type: application/json"); proc.addParameter("-H"); sprintf(buffer, "x-synchronise-public-key: %s", _public_key); proc.addParameter(buffer);

    // Prepare the inputs
    /* Set the component ID            */ /* Set the client as an arduino  */
    inputs->setInput("id", component_id); inputs->setInput("S_C", "arduino"); proc.addParameter("-d");
    // Formats the inputs and stores them in the request
    inputs->_root.printTo(buffer, BUFFER_SIZE); proc.addParameter(buffer);

    // Formats the url of the request
    sprintf(buffer, "https://%s/component/run", server); proc.addParameter(buffer);

    proc.runAsynchronously(); // RUN

    while (!proc.available()) { delay(50); } // Wait for request to be done
    long timestamp = millis();

    // Store the new request in the list of callbacks
    static struct Requests req; // Static to keep it in memore outside of scope
    req.id      = timestamp;
    req.success = success;
    req.error   = error;

    int i = 0;
    bool print = true;
    while (proc.available()) {
        char c = proc.read();
        if (c == '\n')
            print = false;
        if (print)
            Serial.print(c);
    }

    return timestamp; // Return the id of the request
}

long Synchronise::componentRun(const char* component_id, void (*success_callback)(), void (*error_callback)()){
    SynchroniseInputs inputs; // Create empty inputs
    return this->componentRun(&*component_id, &inputs, success_callback, error_callback);
}

long Synchronise::componentRun(const char* component_id, void (*success_callback)()){
    SynchroniseInputs inputs; // Create empty inputs
    return this->componentRun(&*component_id, &inputs, success_callback, NULL);
}

long Synchronise::componentRun(const char* component_id){
    SynchroniseInputs inputs; // Create empty inputs
    return this->componentRun(&*component_id, &inputs, NULL, NULL);
}

long Synchronise::workflowRun(char* component_id, SynchroniseInputs* inputs, void* success_callback, void* error_callback){

}
