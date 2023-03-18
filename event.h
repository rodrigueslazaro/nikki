#ifndef EVENT_H
#define EVENT_H

struct event {
    string name;
    vector<chunk> chunks;
    void show_event() {
        int i=0;
        for (auto c : chunks) {
            i++;
            cout << "---Chunk---: " << i << endl;
            cout << "Name: " << name << endl;
            c.show_chunk();
        }
    }
};

#endif
