#include "timer.h"

Timer::Timer(float seconds) : m_seconds(seconds), m_accumulatedTime(0.F), m_running(false) {}

bool Timer::update(float deltaTime)
{
    if (m_running)
    {
        m_accumulatedTime += deltaTime;
        if (m_accumulatedTime >= m_seconds)
        {
            reset();
            return true;
        }
    }
    return false;
}

void Timer::start()
{
    m_running = true;
}

void Timer::stop()
{
    m_running = false;
}

void Timer::reset()
{
    m_accumulatedTime = 0.F;
    m_running = false;
}

void Timer::restart()
{
    reset();
    start();
}