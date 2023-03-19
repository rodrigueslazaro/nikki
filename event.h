#ifndef EVENT_H
#define EVENT_H

#include "chunk.h"
#include <string>
#include <vector>
using namespace std;

class event {
public:
    event() {}
    event(string new_name, vector<chunk> new_chunks) {
        name = new_name;
        chunks = new_chunks;
    }
    void set_name(string new_name) {
        name = new_name;
    }
    void set_chunk(chunk new_chunk) {
        chunks.push_back(new_chunk);
    }
    string get_name() {
        return name;
    }
    vector<chunk> get_chunks() {
        return chunks;
    }
    void show_event() {
        cout << "Name: " << name << endl;
        for (auto c : chunks) {
            c.show_chunk();
        }
    }
private:
    string name;
    vector<chunk> chunks;
};

#endif
