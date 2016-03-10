#include "SynchroniseOutputs.h"

SynchroniseOutputs::SynchroniseOutputs(){}

void SynchroniseOutputs::setOutput(const char* name, char value){ _root[name] = value; }
void SynchroniseOutputs::setOutput(const char* name, char* value){ _root[name] = value; }
void SynchroniseOutputs::setOutput(const char* name, const char* value){ _root[name] = value; }
void SynchroniseOutputs::setOutput(const char* name, int value){ _root[name] = value; }
void SynchroniseOutputs::setOutput(const char* name, long value){ _root[name] = value; }
void SynchroniseOutputs::setOutput(const char* name, short value){ _root[name] = value; }
void SynchroniseOutputs::setOutput(const char* name, float value){ _root[name] = value; }
void SynchroniseOutputs::setOutput(const char* name, double value){ _root[name] = value; }
void SynchroniseOutputs::setOutput(const char* name, bool value){ _root[name] = value; }

void SynchroniseOutputs::toString(){ _root.printTo(Serial); }
