/* Synchronise.cpp - Client library to communicate with the REST API of synchronise.io
   Created by Thibaut Rey, March 6, 2016.*/
#include <Bridge.h>
#include "Synchronise.h"
#define BUFFER_SIZE 500

const char *server = "api.synchronise.io"; /* ENDPOINT OF THE SERVER */

Synchronise::Synchronise(const char* public_key){
    _public_key = public_key;
}

void Synchronise::componentRun(const char* component_id, SynchroniseInputs* inputs, SuccessCallback success, ErrorCallback error){
    char buffer[BUFFER_SIZE];
    Process proc; // Static to keep it in memory outside of scope
    proc.begin("curl");
    proc.addParameter("-k");
    proc.addParameter("-X");
    proc.addParameter("POST");
    proc.addParameter("-H");
    proc.addParameter("Content-Type: application/json");
    proc.addParameter("-H");
    sprintf(buffer, "x-synchronise-public-key: %s", _public_key);
    proc.addParameter(buffer);

    inputs->setInput("id", component_id); // Set the component ID
    inputs->setInput("S_C", "arduino"); // Set the client as an arduino
    proc.addParameter("-d");
    inputs->_root.printTo(buffer, BUFFER_SIZE); // Formats the inputs and stores them on the request
    proc.addParameter(buffer);

    sprintf(buffer, "https://%s/component/run", server); // Formats the url of the request
    proc.addParameter(buffer);
    proc.runAsynchronously();

    while (!proc.available()) {
       delay(100);
    }

    long timestamp = millis();

    // Store the new request in the list of callbacks
    static struct Requests req; // static to keep it in memore outside of scope
    req.id      = timestamp;
    req.success = success;
    req.error   = error;
    reqs[0] = &req;

    int i = 0;
    bool print = true;
    while (proc.available()) {
        char c = proc.read();
        if (c == '\n')
            print = false;
        if (print)
            Serial.print(c);
    }

    //return timestamp; // Return the id of the request
}

long Synchronise::componentRun(const char* component_id, void (*success_callback)(), void (*error_callback)()){
    /*SynchroniseInputs inputs; // Create empty inputs
    self->componentRun(component_id, inputs, success_callback, error_callback);*/
}

long Synchronise::componentRun(const char* component_id, void (*success_callback)()){
    /*SynchroniseInputs inputs; // Create empty inputs
    self->componentRun(component_id, inputs, success_callback, void);*/
}

long Synchronise::componentRun(const char* component_id){
    /*SynchroniseInputs inputs; // Create empty inputs
    self->componentRun(component_id, inputs, void, void);*/
}

long Synchronise::workflowRun(char* component_id, SynchroniseInputs* inputs, void* success_callback, void* error_callback){

}
