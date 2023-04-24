#ifndef TIMER_HPP
#define TIMER_HPP

#include <chrono>

namespace vEngine::core::utils
{

using Duration = std::chrono::duration<double, std::nano>;

class TimeStamp
{
public:
    using nanoToMilli = std::ratio<1, 1000>;
    // using nanoToSecond = std::ratio<

    TimeStamp(): duration(0) {}
    TimeStamp(const Duration duration): duration(duration) {}

    double asNanoseconds() const { return duration.count(); }
    double asMilliseconds() const { return std::chrono::duration<double, std::milli>(duration).count(); }
    double asSeconds() const { return std::chrono::duration<double, std::ratio<1, 1>>(duration).count(); }

private:
    Duration duration;
};

template <typename ClockType = std::chrono::high_resolution_clock>
class Timer
{
public:
    Timer()
    {
        start();
    }
    ~Timer() = default;

    void start()
    {
        startTimestamp = ClockType::now();
        lastTimestamp = startTimestamp;
    }
    
    void clearStartTime()
    {
        startTimestamp = ClockType::now();
    }

    void setTimestamp()
    {
        lastTimestamp = ClockType::now();
    }

    TimeStamp getElapsedTimeSinceTimestamp()
    {
        const auto timestamp = ClockType::now();
        return TimeStamp{Duration{timestamp - lastTimestamp}};
    }

    TimeStamp getElapsedTimeSinceStart()
    {
        const auto timestamp = ClockType::now();
        return TimeStamp(Duration{timestamp - startTimestamp});
    }

private:
    std::chrono::time_point<ClockType> startTimestamp;
    std::chrono::time_point<ClockType> lastTimestamp;
};

}

#endif // TIMER_HPP