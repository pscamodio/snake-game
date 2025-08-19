#pragma once

class Timer
{
  public:
    Timer(float seconds);
    bool update(float deltaTime);

    void start();
    void stop();
    void reset();
    void restart();

  private:
    float m_seconds;
    float m_accumulatedTime;
    bool m_running;
};