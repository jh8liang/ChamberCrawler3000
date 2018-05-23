#ifndef OBSERVER_H_INCLUDED
#define OBSERVER_H_INCLUDED
class Subject;
class Cell;

class Observer
{
public:
    virtual void notify(Subject &whoNotified) = 0;
    virtual ~Observer() = default;
};

#endif // OBSERVER_H_INCLUDED
