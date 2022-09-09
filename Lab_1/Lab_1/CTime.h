#ifndef C_TIME_H
#define C_TIME_H

class Time
{
public:
    Time(int hour, int min, int sec);
    Time();
    int get_hours() const;
    int get_minutes() const;
    int get_seconds() const;
    int seconds_from(Time t) const;
    void add_seconds(int s);
private:
    int time_in_secs;
};

#endif
