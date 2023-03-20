#include "schedule.h"
#include "chunk.h"
#include "event.h"
#include "constants.h"
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

vector<string> break_weekdays_into_vector(string str) {
    stringstream ss(str);
    vector<string> new_weekdays_array;
    string token;
    while (getline(ss, token, ' ')) {
        new_weekdays_array.push_back(token);
    }
    return new_weekdays_array;
}

void schedule::assign_today_schedule() {
    ofstream schedule_file(NIKKI_DIR+TODAY_DATE+".nk", ios::trunc);
    int c = 0;
    if (schedule_file.is_open()){
        schedule_file << "「" 
                      << TODAY_DATE.substr(0,4)
                      << "年" 
                      << TODAY_DATE.substr(5,2) 
                      << "月"
                      << TODAY_DATE.substr(8,2)
                      << "日"
                      << TODAY_IN_WEEK_JP
                      << "」" << endl << endl;
        if (!TRACKERS.empty()) {
            schedule_file << "__記録 ~~~φ(・∀・*)__" << endl;
            for (auto tracker : TRACKERS) {
                schedule_file << "__" << tracker << ": " <<endl;
            }
            schedule_file << "---------------------" << endl << endl;
        }
        if (!events.empty()) {
            schedule_file << "__日程 ｡*(ノ°益°)ノ__" << endl << endl;
            for (auto event : events) {
                if (event.get_name().find("$") != -1) {
                    schedule_file << event.get_name() << endl;
                } else {
                    schedule_file << event.get_name() << " $white" << endl;
                }
                for (auto chunk : event.get_chunks()) {
                    schedule_file << "  "<< chunk.get_time() << endl;
                    for (auto todo : chunk.get_todos()) {
                        schedule_file << "  TODO" << todo << endl;
                    }
                }
                schedule_file << endl;
            }
        }
        
        schedule_file.close();
    } else {
        cout << "Unable to open file." << endl;
    }
}

bool compare_time(const event& a, const event& b) {
    return a.get_chunks()[0].get_start() <= b.get_chunks()[0].get_start();
}

void schedule::learn_today_schedule() {
    string line;
    ifstream file(NIKKI_DIR+SCHEDULE_FILE_NAME);
    event new_event;
    chunk new_chunk;
    string new_name;
    string new_weekdays;
    string new_time_range;
    vector<string> new_todos;
    int new_time;
    vector<string> new_weekdays_array;
    bool is_scheduled_for_today = false;

    if (file.is_open()) {
        while (getline(file, line)) {
            if (line.find("__") == 0){
                new_event.set_name(line);
            }
            else if (line.find("  # ") != -1) {
                new_weekdays = line.substr(4);
                new_weekdays_array = break_weekdays_into_vector(new_weekdays);
            }
            else if (line.find(" to ") != -1){
                new_time_range = line.substr(2);
                new_time = stoi(new_time_range.substr(0,new_time_range.find(":")));
            }
            else if (line.find("  - ") != -1) {
                new_todos.push_back(line.substr(3));
            }
            else if (line.find("---") != -1 || line.empty()) {
                for (auto day_in_week : new_weekdays_array) {
                    if (day_in_week.find(TODAY_IN_WEEK) != -1) {
                        new_chunk.set_time(new_time_range);
                        new_chunk.set_start(new_time);
                        new_chunk.set_todos(new_todos);
                        new_chunk.set_weekday(day_in_week);
                        new_event.set_chunk(new_chunk);
                        new_chunk = chunk();
                        new_weekdays = "";
                        new_weekdays_array.clear();
                        new_todos.clear();
                        is_scheduled_for_today = true;
                    }
                }
                if (line.empty()) {
                    if (is_scheduled_for_today) {
                        events.push_back(new_event);
                        is_scheduled_for_today = false;
                    }
                    new_chunk = chunk();
                    new_weekdays = "";
                    new_weekdays_array.clear();
                    new_todos.clear();
                    new_event = event();

                }
            }
        }
        file.close();
    } else {
        cout << "Unable to open file\n";
    }
    /*
    for (auto e : events) {
        cout << e.get_chunks()[0].get_start() << endl;
    }
    */
    sort(events.begin(), events.end(), compare_time);
}
