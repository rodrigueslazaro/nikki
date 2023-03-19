#ifndef CHUNK_H
#define CHUNK_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class chunk {
public:
    chunk() {}
    chunk(string new_time, string new_weekday,
          vector<string> new_todos, int new_start) {
        time = new_time;
        weekday = new_weekday;
        todos = new_todos;
        start = new_start;
    }
    void set_time(string new_time) {
        time = new_time;
    }
    void set_weekday(string new_weekday) {
        weekday = new_weekday;
    }
    void set_todos(vector<string> new_todos) {
        todos = new_todos;
    }
    void set_start(int new_start) {
        start = new_start;
    }
    vector<string> get_todos() {
        return todos;
    }
    string get_time() {
        return time;
    }
    void show_chunk() {
        cout << "---Chunk---: " << endl;
        cout << "Time: " << time << endl;
        cout << "Weekday: " << weekday << endl;
        cout << "Start: " << start << endl;
        for (auto s : todos) {
            cout << "TODO " << s << endl;
        }
    }
private:
    string time, weekday;
    vector<string> todos;
    int start;
};

#endif
