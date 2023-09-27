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
        Logger* CreateLoggerObject(std::string s) {
            if(s.compare("Error") == 0) {
                return new Error(); 
            }
            else if(s.compare("Debug") == 0) {
                return new Debug();
            }
            else if(s.compare("Info") == 0) {
                return new Info();
            }
            else {
                return nullptr;
            }
        }
};

int main() {
    LoggerFactory *objFactory = new LoggerFactory();
    Logger* obj = objFactory->CreateLoggerObject("Error");
    obj->log();

    obj = objFactory->CreateLoggerObject("Info");
    obj->log();

    delete objFactory;
    delete obj;
}