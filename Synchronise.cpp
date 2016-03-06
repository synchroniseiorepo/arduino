/*
    Synchronise.cpp - Client library to communicate with the REST API of synchronise.io
    Created by Thibaut Rey, March 6, 2016.
*/

#include "Arduino.h"
#include "Morse.h"

// ENDPOINT OF THE SERVER
const char *server = "api.synchronise.io";

Synchronise::Synchronise(char* public_key){
    _public_key = public_key;
}

void Synchronise::componentRun(char* component_id, SynchroniseInput* inputs, void* success_callback, void* error_callback){
    Process proc;

    proc.begin("curl");
    proc.addParameter("-k");
    proc.addParameter("-X");
    proc.addParameter("POST");
    proc.addParameter("-H");
    proc.addParameter("Content-Type: application/json");
    proc.addParameter("-H");
    sprintf(buffer, "x-synchronise-public-key: %s", _public_key);
    proc.addParameter(buffer);
    // Formats the inputs
    proc.addParameter("-d");

    sprintf(buffer, "https://%s/%s/%s", server, endpoint, method);
    proc.addParameter(buffer);
    proc.run();
}
