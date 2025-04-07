#ifndef YBT_TIMER_H
#define YBT_TIMER_H

#include <decl.hpp>

/*!
 * Timer for measuring time elapsed with clock_monotonic
 */
class Timer {
 public:

  /*!
   * Construct and start timer  
   */
  explicit Timer() { start(); }

  /*!
   * Start the timer
   */
  void start() { clock_gettime(CLOCK_MONOTONIC, &_startTime); }

  /*!
   * Get milliseconds elapsed
   */
  double getMs() { return (double)getNs() / 1.e6; }

  /*!
   * Get nanoseconds elapsed
   */  
  int64_t getNs() {
    struct timespec now;
    clock_gettime(CLOCK_MONOTONIC, &now); //当前到时间
    return (int64_t)(now.tv_nsec - _startTime.tv_nsec) +
           1000000000 * (now.tv_sec - _startTime.tv_sec); //减去开始到时间，得到经过到时间，按照纳秒时间单位
  }

  /*!
   * Get seconds elapsed
   */
  double getSeconds() { return (double)getNs() / 1.e9; } // 返回经过到时间，按照秒为单位

  struct timespec _startTime;
};

#endif  // YBT_TIMER_H
