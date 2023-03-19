#include "date_utils.h"
#include <string>
#include <vector>
using namespace std;

const string SCHEDULE_FILE_NAME = "schedule.nk";
const string NIKKI_DIR = "/home/lazaro/nikki/";
const int ONLY_ONE_WEEK = 3;
const string TODAY_DATE = get_date();
const string TODAY_IN_WEEK = get_weekday();
const string TODAY_IN_WEEK_JP = get_weekday_jp();
const vector<string> TRACKERS = {"睡眠","気分","食品","ヨガ","運動"};
