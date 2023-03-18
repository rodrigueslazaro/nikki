#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

int main() {
    ifstream input_file("2023-03-18.nk");
    string line;

    map<std::string, std::string> colors = {
        {"red", "31"},
        {"green", "32"},
        {"yellow", "33"},
        {"blue", "34"},
        {"purple", "35"},
        {"cyan", "36"},
        {"white", "37"}
    };

    if (input_file.is_open()) {
        string color_name;
        size_t color_pos;
        int todos = -1;
        while (getline(input_file, line)) {
            if ((line.find("__") != -1 && line.find("§") != -1)
                || line.find("to") != -1
                || line.find("TODO") != -1) {
                if ((color_pos = line.find("§")) != -1) {
                    color_name = line.substr(color_pos+2);
                    system(("echo \e["+colors[color_name]+"m"
                                    +line.substr(0, color_pos)
                                    +"\e[0m").c_str());
                } else {
                    todos++;
                    system(("echo \e["+colors[color_name]+"m"
                                    +line
                                    +"\e[0m").c_str());

                }
            }
        }
        input_file.close();
    } else {
        cout << "Error opening file!" << endl;
    }

    input_file.close();

    return 0;
}

