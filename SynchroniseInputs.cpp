#include "SynchroniseInputs.h"

SynchroniseInputs::SynchroniseInputs(){}

void SynchroniseInputs::setInput(const char* name, char value){ _root[name] = value; }
void SynchroniseInputs::setInput(const char* name, char* value){ _root[name] = value; }
void SynchroniseInputs::setInput(const char* name, const char* value){ _root[name] = value; }
void SynchroniseInputs::setInput(const char* name, int value){ _root[name] = value; }
void SynchroniseInputs::setInput(const char* name, long value){ _root[name] = value; }
void SynchroniseInputs::setInput(const char* name, short value){ _root[name] = value; }
void SynchroniseInputs::setInput(const char* name, float value){ _root[name] = value; }
void SynchroniseInputs::setInput(const char* name, double value){ _root[name] = value; }
void SynchroniseInputs::setInput(const char* name, bool value){ _root[name] = value; }

void SynchroniseInputs::toString(){ _root.printTo(Serial); }
