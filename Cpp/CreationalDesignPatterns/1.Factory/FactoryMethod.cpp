
#include<iostream>

class Logger {
    public:
        virtual void log()=0;
};

class Error: public Logger {
    public:
        void log() {
            std::cout<<"Error: msg"<<std::endl;
        }
};

class Debug: public Logger {
    public:
        void log() {
            std::cout<<"Debug: msg"<<std::endl;
        }
};

class Info: public Logger {
    public:
        void log() {
            std::cout<<"Info: msg"<<std::endl;
        }
};

class LoggerFactory {
    public:
        virtual Logger* CreateLoggerObject()=0;
};

class ErrorLogFactory : public LoggerFactory{
    public:
        Logger* CreateLoggerObject() {
            return new Error();
        }
};

class DebugLogFactory : public LoggerFactory{
    public:
        Logger* CreateLoggerObject() {
            return new Debug();
        }
};

class InfoLogFactory : public LoggerFactory {
    public:
        Logger* CreateLoggerObject() {
            return new Info();
        }
};

int main() {
    LoggerFactory *loggerFactoryObj = new ErrorLogFactory();
    Logger *logObj1 = loggerFactoryObj -> CreateLoggerObject();

    loggerFactoryObj = new InfoLogFactory();
    Logger *logObj2 = loggerFactoryObj -> CreateLoggerObject();

    logObj1 -> log();
    logObj2 -> log();

    //cleaning up the pointers
    delete loggerFactoryObj;
    delete logObj1;
    delete logObj2;
}