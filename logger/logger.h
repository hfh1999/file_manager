/**
 * @author Feihuang Huang
 * @email huang-feihuang@qq.com
 * @create date 2024-03-02 22:05:09
 * @desc [simple Logger (single thread)]
 */

#ifndef LOGGER_H
#define LOGGER_H
#include <memory>
#include <string>
enum class LoggerLevel { DEBUG, INFO, WARN, ERROR };

using std::unique_ptr;
using std::string;
class Logger {
private:
  Logger();
  static unique_ptr<Logger> &get_logger_();
  static LoggerLevel logger_level_;
  static void route_(LoggerLevel level, const string& out_content);

public:
  static void set_logger_level(LoggerLevel level);

  static void debug(const string&);
  static void info(const string&);
  static void warn(const string&);
  static void error(const string&);
  static void set_level(LoggerLevel level);
};
#endif