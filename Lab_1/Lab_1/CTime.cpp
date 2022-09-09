#include "CTime.h"
#include <ctime>
#include <cassert>
using namespace std;

/*
    Các ký hiệu không được chấp nhận bằng cách sử dụng công cụ
    sửa đổi __declspec (không được dùng nữa) hoặc thuộc tính C ++ 14 [[không được dùng]].
    Thông báo cảnh báo C4996 thực tế được chỉ định bởi công cụ sửa đổi hoặc thuộc tính 
    không dùng nữa của khai báo.
*/
// tắt warning 4996.
#pragma warning(disable : 4996)

int remainder(int a, int n)
{
    if (a >= 0)
        return a % n;
    else
        return n - 1 - (-a - 1) % n;
}
/*
    Nếu bieu-thuc ước lượng là TRUE, thì assert() không làm điều gì. 
    Nếu bieu-thuc ước lượng là false, thì assert() hiển thị một thông 
    báo lỗi trên stderr và ngừng thực thi chương trình.
*/
Time::Time(int hour, int min, int sec)
{
    assert(0 <= hour);
    assert(hour < 24);
    assert(0 <= min);
    assert(min < 60);
    assert(0 <= sec);
    assert(sec < 60);
    time_in_secs = 60L * 60 * hour + 60 * min + sec;
}


/*
    Hàm localtime() nhận một con trỏ kiểu time_t làm đối số của nó và 
    trả về một đối tượng con trỏ của cấu trúc tm. 
    Giá trị được trả về bởi hàm localtime() là giờ cục bộ (local time).

    Sau đó, giờ, phút và giây có thể được truy cập bằng tm_hour, tm_min và tm_sec.
*/
Time::Time()
{
    //khai báo biến curr_time để biểu diễn thời gian hiện tại
    time_t curr_time = time(NULL);
    //sử dụng hàm localtime() để chuyển đổi format cho curr_time
    struct tm& t = *localtime(&curr_time);
    time_in_secs = 60L * 60 * t.tm_hour + 60 * t.tm_min + t.tm_sec;
}

int Time::get_hours() const
{
    return time_in_secs / (60 * 60);
}

int Time::get_minutes() const
{
    return (time_in_secs / 60) % 60;
}

int Time::get_seconds() const
{
    return time_in_secs % 60;
}

int Time::seconds_from(Time t) const
{
    return time_in_secs - t.time_in_secs;
}

void Time::add_seconds(int s)
{
    const int SECONDS_PER_DAY = 60 * 60 * 24;
    time_in_secs = remainder(time_in_secs + s, SECONDS_PER_DAY);
}