#include "date_utils.h"
#include "schedule.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <sstream>
using namespace std;

const string SCHEDULE_FILE_NAME = "schedule.nk";
const int ONLY_ONE_WEEK = 3;
const string TODAY_DATE = get_date();
const string TODAY_IN_WEEK = get_weekday();
const string TODAY_IN_WEEK_JP = get_weekday_jp();

vector<string> break_weekdays_into_vector(string str) {
    stringstream ss(str);
    vector<string> new_weekdays_array;
    string token;
    while (getline(ss, token, ' ')) {
        new_weekdays_array.push_back(token);
    }
    return new_weekdays_array;
}

int main(){
    return 0;
}
