//
// Created by drlim on 22/01/2021.
//

#ifndef PROFESSIONAL_ENGINEERING_COURSEWORK_EVENTINTERVALTRIGGER_H
#define PROFESSIONAL_ENGINEERING_COURSEWORK_EVENTINTERVALTRIGGER_H

#include <chrono>

using namespace std::chrono_literals;

/**
 * A timer that allows events to be triggered without pausing a thread. This timer accounts for processing time to
 * provide regular intervals. Provides up to microsecond precision.
 * @author - David Lim
 */
class EventIntervalTrigger {
public:
    /**
     * Constructor for the timer object.
     * @param interval - The time between triggers as a duration (eg. std::chrono::microseconds,
     *                   std::chrono::milliseconds, std::chrono::seconds...)
     */
    explicit EventIntervalTrigger(std::chrono::microseconds interval);

    /**
     * Start the timer. Function also can be used to restart the timer. Once started first trigger is immediate.
     * @param currentTime - The current time between as a duration (eg. std::chrono::microseconds,
     *                      std::chrono::milliseconds, std::chrono::seconds... lower precision may result in random
     *                      interval for first trigger)
     */
    void start(std::chrono::microseconds currentTime);

    /**
     * Start the timer. Function also can be used to restart the timer. Once started first trigger is the interval after
     * the timer is started.
     * @param currentTime - The current time between as a duration (eg. std::chrono::microseconds,
     *                      std::chrono::milliseconds, std::chrono::seconds... lower precision may result in random
     *                      interval for first trigger)
     */
    void startNext(std::chrono::microseconds currentTime);

    /**
     * Stops the timer. When the timer is paused hasElapsed() will always return false.
     */
    void stop();

    /**
     * Checks whether the timer should be triggered.
     * @param currentTime - The current time between as a duration (eg. std::chrono::microseconds,
     *                      std::chrono::milliseconds, std::chrono::seconds... lower precision may result in random
     *                      interval for first trigger)
     * @return - Whether the timer has triggered as a boolean value
     */
    bool hasElapsed(std::chrono::microseconds currentTime);

    /**
     * Sets the interval time to a new time period.
     * @param interval - The time between triggers as a duration (eg. std::chrono::microseconds,
     *                   std::chrono::milliseconds, std::chrono::seconds...)
     */
    void setInterval(std::chrono::microseconds interval);

private:
    std::chrono::microseconds startTime = 0ms;
    std::chrono::microseconds interval;
    bool running = false;
    long long eventCounter = 0;
};

#endif //PROFESSIONAL_ENGINEERING_COURSEWORK_EVENTINTERVALTRIGGER_H
