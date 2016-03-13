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
            SynchroniseOutputs(const char *json, uint8_t sizeBuffer);
            void setBool(const char * key, bool value);

            bool getBool(const char * key);
            char getChar(const char * key);
            long getLong(const char * key);
            int getInt(const char * key);
            short getShort(const char * key);
            float getFloat(const char * key);
            double getDouble(const char * key);
            const char* getConstChar(const char * key);

        private:
            JsonObject* _root;
    };

#endif
