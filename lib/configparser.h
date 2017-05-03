#ifndef __CONFIG_PARSER_H__
#define __CONFIG_PARSER_H__

#include <string>
#include <map>
#include <vector>
using namespace std;

class LaConfigParser
{
    public:
        ~LaConfigParser();

    public:
        static LaConfigParser* create_instance(const char* conf="etc/lasync.conf", const char* delimeter="=", bool allow_duplicate_key=true);

    public:
        const char* read_plugin_dir();
        const char* read_value(const char* key);
        const std::string read_value(const std::string& key);
        static bool map_has_key(std::map<std::string, std::string>* map_ptr, std::string key);
        void dump();//dump the map result
    private:
        std::string path;
        std::string delimiter;
        bool allow_duplicate_key;//judge the key is duplicate or not
        LaConfigParser(const char* path, const char* delimiter = "=", bool allow_duplicate_key = true);
        LaConfigParser(std::string path, const char* delimeter = "=", bool allow_duplicate_key = true);

        std::map<std::string, std::string>* read_all();
        std::map<std::string, std::string>* key_value_map;
        vector<std::string>* lines;
        void read_config();
};

#endif
