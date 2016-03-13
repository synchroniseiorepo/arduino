#include "SynchroniseOutputs.h"

SynchroniseOutputs::SynchroniseOutputs(const char *json, uint8_t sizeBuffer){
    StaticJsonBuffer<200> jsonBuffer;
    _root = &jsonBuffer.parseObject(&*json, sizeBuffer);
}

void SynchroniseOutputs::set(const char * key, int value){
    _root->set(key, value);
}

bool SynchroniseOutputs::getBool(const char * key){
    return _root->get(key);
}

char SynchroniseOutputs::getChar(const char * key){
    return _root->get(key);
}

long SynchroniseOutputs::getLong(const char * key){
    return _root->get(key);
}

int SynchroniseOutputs::getInt(const char * key){
    return _root->get(key);
}

short SynchroniseOutputs::getShort(const char * key){
    return _root->get(key);
}

float SynchroniseOutputs::getFloat(const char * key){
    return _root->get(key);
}

double SynchroniseOutputs::getDouble(const char * key){
    return _root->get(key);
}

const char* SynchroniseOutputs::getConstChar(const char * key){
    return _root->get(key);
}
