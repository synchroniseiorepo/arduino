/*
    SynchroniseInputs.h - Client library to communicate with the REST API of synchronise.io
    Created by Thibaut Rey, March 6, 2016.
*/
#ifndef Synchronise_inputs_h
#define Synchronise_inputs_h

    #include "Arduino.h"
    #include <ArduinoJson.h>

    class SynchroniseInputs{
        public:
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

            void toString();

            StaticJsonBuffer<200> jsonBuffer;
            JsonObject& _root = jsonBuffer.createObject();
    };

#endif
