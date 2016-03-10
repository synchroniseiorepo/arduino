/*
    SynchroniseOutputs.h - Client library to communicate with the REST API of synchronise.io
    Created by Thibaut Rey, March 6, 2016.
*/
#ifndef Synchronise_outputs_h
#define Synchronise_outputs_h

    #include "Arduino.h"
    #include <ArduinoJson.h>

    class SynchroniseOutputs{
        public:
            SynchroniseOutputs();
            void setOutputs(const char* name, char value);
            void setOutputs(const char* name, char* value);
            void setOutputs(const char* name, const char* value);
            void setOutputs(const char* name, int value);
            void setOutputs(const char* name, long value);
            void setOutputs(const char* name, short value);
            void setOutputs(const char* name, float value);
            void setOutputs(const char* name, double value);
            void setOutputs(const char* name, bool value);

            void toString();

            StaticJsonBuffer<200> jsonBuffer;
            JsonObject& _root = jsonBuffer.createObject();
    };

#endif
