/*
    Synchronise.h - Client library to communicate with the REST API of synchronise.io
    Created by Thibaut Rey, March 6, 2016.
*/
#ifndef Synchronise_h
#define Synchronise_h

    #include "Arduino.h"
    #include "SynchroniseInputs.h"

    class Synchronise{
        public:
            Synchronise(char* public_key);
            void componentRun(char* component_id, SynchroniseInput* inputs, void* success_callback, void* error_callback);
            void workflowRun(char* component_id, SynchroniseInputs* inputs, void* success_callback, void* error_callback);
        private:
            char* _public_key;
    };

#endif
