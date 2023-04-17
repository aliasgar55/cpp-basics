# include <iostream>
class Log {
    public:

        // LogLevel is not a namespace of the error warn and info exits in the Log class
        enum LogLevel: char {
            error = 0, warn = 1, info = 2
        };
    private:
        LogLevel m_LogLevel;

    public: 
        void setLevel(LogLevel level) {
            m_LogLevel = level;
        }

        void Error(const char* message) {
            if (m_LogLevel >= error)
            std::cout << "[ERROR]: " << message << std::endl;
        }
        void Warn(const char* message) {
            if (m_LogLevel >= warn)
            std::cout << "[WARNING]: " << message << std::endl;
        }
        void Info(const char* message) {
            if (m_LogLevel >= info)
            std::cout << "[INFO]: " << message << std::endl;
        }
};

int main() {

    Log logger = Log();
    logger.setLevel(Log::error);
    logger.Info("Hello");
}

