#include <iterator>
#include <regex.h>
#include "configparser.h"
#include "fsutils.h"

LaConfigParser::LaConfigParser(const char* path, const char* delimiter, bool allow_duplicate_key)
{
    this->path = std::string(path);
    this->delimiter = std::string(delimiter);
    this->allow_duplicate_key = allow_duplicate_key;
    this->lines = new vector<std::string>;
    this->key_value_map = new map<std::string, std::string>;
    this->read_config();
    this->read_all();
}
LaConfigParser::~LaConfigParser()
{
    if(this->lines)
    {
        delete this->lines;
        this->lines = NULL;
    }
    if(this->key_value_map)
    {
         delete this->key_value_map;
         this->key_value_map = NULL;
    }
}
LaConfigParser::LaConfigParser(std::string path, const char* delimiter, bool allow_duplicate_key)
{
    this->path = path;
    this->delimiter = std::string(delimiter);
    this->allow_duplicate_key = allow_duplicate_key;
    this->lines = new vector<std::string>;
    this->key_value_map = new map<std::string, std::string>;
    this->read_config();
    this->read_all();
}
LaConfigParser* LaConfigParser::create_instance(const char* conf, const char* delimiter, bool allow_duplicate_key)
{
    if(!LaFsUtils::exists(conf) || !LaFsUtils::isfile(conf))
    {

    }
    return new LaConfigParser(conf, delimiter, allow_duplicate_key);
}
const char* LaConfigParser::read_plugin_dir()
{

}
const char* LaConfigParser::read_value(const char* key)
{

}
const std::string LaConfigParser::read_value(const std::string& key)
{

}
bool LaConfigParser::map_has_key(std::map<std::string, std::string>* map_ptr, std::string key)
{

}
void LaConfigParser::dump()
{

}
map<std::string, std::string>* LaConfigParser::read_all()
{

}
void LaConfigParser::read_config()
{

}
