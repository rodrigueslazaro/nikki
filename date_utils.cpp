#include "date_utils.h"
#include <chrono>
#include <iomanip>
#include <sstream>

std::string get_date_weekday() {
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    std::time_t time_now = std::chrono::system_clock::to_time_t(now);
    std::tm* tm_now = std::localtime(&time_now);
    int weekday = tm_now->tm_wday;
    std::string weekdays[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    std::string weekdays_jp[] = {"日", "月", "火", "水", "木", "金", "土"};
    std::string weekday_str = weekdays[weekday];
    std::string weekday_str_jp = weekdays_jp[weekday];
    std::ostringstream oss;
    oss << std::put_time(tm_now, "%Y-%m-%d");
    std::string date_str = oss.str();
    date_str += weekday_str + weekday_str_jp;
    return date_str;
}

std::string get_date() {
    return get_date_weekday().substr(0,10);
}

std::string get_weekday() {
    return get_date_weekday().substr(10,3);
}

std::string get_weekday_jp() {
    return get_date_weekday().substr(13);
}
