#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <vector>
#include "event.h"
using namespace std;

class schedule {
public:
    schedule() {}
    schedule(vector<event> new_events) {
        events = new_events;
    }    
    void set_event(event new_event) {
        events.push_back(new_event);
    }
    void assign_today_schedule();
    void learn_today_schedule();
    void show_schedule() {
        for (auto e : events) {
            e.show_event();
        }        
    }
private:
    vector<event> events;
};

#endif
