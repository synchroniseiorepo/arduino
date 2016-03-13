/*
    Synchronise.h - Client library to communicate with the REST API of synchronise.io
    Created by Thibaut Rey, March 6, 2016.
*/
#ifndef Synchronise_h
#define Synchronise_h

    #include "Arduino.h"
    #include "SynchroniseInputs.h"
    #include "SynchroniseOutputs.h"
    #include <Process.h>

    typedef void (*SuccessCallback)(SynchroniseOutputs *outputs);
    typedef void (*ErrorCallback)(SynchroniseOutputs *outputs);

    class Synchronise{
        public:
            Synchronise(const char* public_key);
            SynchroniseOutputs componentRun(const char* component_id, SynchroniseInputs* inputs);
            SynchroniseOutputs componentRun(const char* component_id);

        private:
            SynchroniseOutputs sendRequest(const char*id_element, const char* type_request, SynchroniseInputs* inputs, SuccessCallback *success, ErrorCallback *error);

            const char* _public_key;
    };

#endif
