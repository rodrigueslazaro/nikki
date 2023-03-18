#ifndef CHUNK_H
#define CHUNK_H

struct chunk {
    string time, weekday;
    vector<string> todos;
    int start;
    void show_chunk() {
        cout << "---Chunk---: " << endl;
        cout << "Time: " << time << endl;
        cout << "Weekday: " << weekday << endl;
        cout << "Start: " << start << endl;
        for (auto s : todos) {
            cout << "TODO " << s << endl;
        }
    }
};

#endif
