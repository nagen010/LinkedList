#include "Factory01.h"
#include "SingleNode.h"
#include "SingleList.h"

Factory01::Factory01()
{
}

Factory01::~Factory01()
{
}
 
void * Factory01::create(std::string name)
{
  if(name == "ISingleNode"){
    return new SingleNode();
  } else if(name == "ISingleList"){
    return NULL;
  } else if(name == "IDoubleNode"){
    return NULL;
  } else if(name == "IDoubleList"){
    return NULL;
  } else {
    return NULL;
  }
}

extern "C" {

ObjectFactory * createObjectFactory(){
  return new Factory01();  
}

}
