#include "schedule.h"
#include "chunk.h"
#include "event.h"

void assign_today_schedule() {
    ofstream schedule_file(TODAY_DATE+".nk", ios::trunc);
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
        schedule_file << "__記録 ~~~φ(・∀・*)__\n"
                      << "__睡眠: \n"
                      << "__気分: \n"
                      << "__食品: \n"
                      << "__ヨガ: \n"
                      << "__運動: \n"
                      << "---------------------\n\n"
                      << "__日程 ｡*(ノ°益°)ノ__" << endl;
        for (auto event : events) {
            for (auto chunk : event.chunks) {
                schedule_file << endl
                              << event.name 
                              << endl
                              << chunk.time
                              << endl;
                c++;
                cout << chunk.time << endl;
                cout << event.name << endl;
            }
        }
        schedule_file.close();
    } else {
        cout << "Unable to open file." << endl;
    }
}

void learn_today_schedule() {
    string line;
    ifstream file(SCHEDULE_FILE_NAME);
    schedule sch;
    event new_event;
    chunk new_chunk;
    string new_weekdays;
    string new_time_range;
    vector<string> new_todos;
    vector<string> new_weekdays_array;
    int new_time;
    bool is_only_one_week_day = true;

    if (file.is_open()) {
        while (getline(file, line)) {
            if (!line.empty()) {
                if (line.find("__") == 0){ // then we've found a new event
                    new_event.name = line;
                }
                if (line.find("  # ") != -1) { // then we've found a new chunk
                    new_weekdays = line.substr(4);
                    if (new_weekdays.size() > ONLY_ONE_WEEK) {
                        new_weekdays_array = break_weekdays_into_vector(new_weekdays);
                        is_only_one_week_day = false;
                    }
                }
                if (line.find(" to ") != -1){ // then we've found the time of the chunk
                    new_time_range = line.substr(2);
                    new_time = stoi(new_time_range.substr(0,new_time_range.find(":")));
                }
                if (line.find("  - ") != -1) { // then we've found a todo for the chunk
                    new_todos.push_back(line.substr(3));
                }
                if (line.find("---") != -1) { // then we've found a new chunk!
                    if (is_only_one_week_day && new_weekdays.find(TODAY_IN_WEEK) != -1) {
                        new_chunk.time = new_time_range;
                        new_chunk.start = new_time;
                        new_chunk.weekday = TODAY_IN_WEEK;
                        new_chunk.todos = new_todos;
                        new_event.chunks.push_back(new_chunk);
                        new_chunk = chunk();
                    } else {
                        for (auto day_in_week : new_weekdays_array) {
                            if (day_in_week.find(TODAY_IN_WEEK) != -1){
                                new_chunk.time = new_time_range;
                                new_chunk.start = new_time;
                                new_chunk.weekday = day_in_week;
                                new_chunk.todos = new_todos;
                                new_event.chunks.push_back(new_chunk);
                                new_chunk = chunk();
                            }
                        }
                    }
                }
            } else {
                new_event.show_event();
                sch.events.push_back(new_event);
                new_event = event();
                new_weekdays_array.clear();
            }
            is_only_one_week_day = true;
        }
        file.close();
    } else {
        cout << "Unable to open file\n";
    }
    sch.assign_today_schedule();
}