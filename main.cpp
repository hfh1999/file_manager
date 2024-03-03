/**
 * @author Feihuang Huang
 * @email huang-feihuang@qq.com
 * @create date 2024-03-02 22:04:34
 */

#include "logger/logger.h"
int main() {
    Logger::set_logger_level(LoggerLevel::INFO);
    Logger::info("Hello world ???");
}