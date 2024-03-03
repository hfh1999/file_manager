/**
 * @author Feihuang Huang
 * @email huang-feihuang@qq.com
 * @create date 2024-03-02 22:06:01
 * @desc [Simple Logger]
 */

#include "logger.h"
#include <cstdio>
#include <memory>
bool operator<(LoggerLevel lhs, LoggerLevel rhs) {
    return static_cast<int>(lhs) < static_cast<int>(rhs);
}

bool operator>(LoggerLevel lhs, LoggerLevel rhs) {
    return static_cast<int>(lhs) > static_cast<int>(rhs);
}

bool operator<=(LoggerLevel lhs, LoggerLevel rhs) {
    return static_cast<int>(lhs) <= static_cast<int>(rhs);
}

bool operator>=(LoggerLevel lhs, LoggerLevel rhs) {
    return static_cast<int>(lhs) >= static_cast<int>(rhs);
}

LoggerLevel Logger::logger_level_ = LoggerLevel::ERROR;

std::unique_ptr<Logger> &Logger::get_logger_() {
  static std::unique_ptr<Logger> instance(new Logger());
  return instance;
}

void Logger::set_level(LoggerLevel level) {
    logger_level_ = level;
}

void log_stdout_(const string& out) {
    printf("%s", out.c_str());
}

void Logger::route_(LoggerLevel level, const string &out_content) {
    if (level >= logger_level_) {
        log_stdout_(out_content);
    }
}

void Logger::debug(const string& output) {
    route_(LoggerLevel::DEBUG, output);
}

void Logger::info(const string& output) {
    route_(LoggerLevel::INFO, output);
}

void Logger::warn(const string& output) {
    route_(LoggerLevel::WARN, output);
}

void Logger::error(const string& output) {
    route_(LoggerLevel::ERROR, output);
}