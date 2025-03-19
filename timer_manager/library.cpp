#include "library.hpp"
#include <iostream>


    void EventScheduler::add_event(int time, const std::string& event) {
        events[time] = event;
        time_queue.push(time);
    }

    std::string EventScheduler::process_next() {
        if (time_queue.empty()) {
            return "";
        }

        int next_time = time_queue.top();
        time_queue.pop();

        std::string event = events[next_time];
        events.erase(next_time);

        return event;
    }
    bool EventScheduler::is_empty() const {
        return time_queue.empty();
    }

    int main() {
        //Basic
        EventScheduler es;
        es.add_event(5, "Backup");
        es.add_event(2, "Update");
        es.add_event(10, "Restart");

        
        while (!es.is_empty()) {
            std::string event = es.process_next();
            std::cout << event << "\n";
        }

        std::cout << "\n";

        //DublicateTimes 
        EventScheduler es2;
        es2.add_event(5, "Backup");
        es2.add_event(5, "Update");

        
        while (!es2.is_empty()) {
            std::string event = es2.process_next();
            std::cout << event << "\n";
        }
    }
