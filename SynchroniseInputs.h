/*
    SynchroniseInputs.h - Client library to communicate with the REST API of synchronise.io
    Created by Thibaut Rey, March 6, 2016.
*/
#ifndef Synchronise_inputs_h
#define Synchronise_inputs_h

    #include "Arduino.h"

    class SynchroniseInputs{
        public:
            SynchroniseInputs();
            void setInput(char* name, char value);
            void setInput(char* name, char* value);
            void setInput(char* name, unsigned char* value);
            void setInput(char* name, int value);
            void setInput(char* name, unsigned int value);
            void setInput(char* name, word value);
            void setInput(char* name, long value);
            void setInput(char* name, unsigned long value);
            void setInput(char* name, short value);
            void setInput(char* name, float value);
            void setInput(char* name, double value);
            void setInput(char* name, bool value);

            void removeInput(char* name);

        private:
            char* _public_key;
    };

#endif
