/*
    Synchronise.h - Client library to communicate with the REST API of synchronise.io
    Created by Thibaut Rey, March 6, 2016.
*/
#ifndef Synchronise_h
#define Synchronise_h

    #include "Arduino.h"
    #include "SynchroniseInputs.h"

    typedef void (*SuccessCallback)();
    typedef void (*ErrorCallback)();

    struct Requests {
        SuccessCallback success;
        ErrorCallback error;
        long id;
    };

    class Synchronise{
        public:
            Synchronise(const char* public_key);

            void componentRun(const char* component_id, SynchroniseInputs* inputs, SuccessCallback success, ErrorCallback error);
            long componentRun(const char* component_id, void (*success_callback)(), void (*error_callback)());
            long componentRun(const char* component_id, void (*success_callback)());
            long componentRun(const char* component_id);

            long workflowRun(char* component_id, SynchroniseInputs* inputs, void* success_callback, void* error_callback);
        private:
            const char* _public_key;
            struct Requests *reqs[2];
    };

#endif
