#ifndef SUBJECT_H_INCLUDED
#define SUBJECT_H_INCLUDED
#include <vector>
#include "cellInfo.h"
#include "observer.h"

class Cells;
class Observer;

class Subject
{
    std::vector<Observer*> observers;

public:
    void attach(Observer *o);
    void notifyObservers();
    virtual Info getInfo() const = 0;
    virtual ~Subject() = 0;
};


#endif // SUBJECT_H_INCLUDED
