//
//  DBTools.h
//  ToolsTemplate
//
//  Created by cesc on 14-3-21.
//
//

#ifndef __ToolsTemplate__DBTools__
#define __ToolsTemplate__DBTools__

#include <string>
#include "sqlite3.h"

struct DBInfo {
    DBInfo(){
        db_name = "";
        sql = "";
        _callback = NULL;
    }
    
    sqlite3_callback _callback;
    std::string db_name;
    std::string sql;
    
    
};

class DBTools  {
    
public:
    
    bool createTable( DBInfo& dbInfo );
    
    
};


#endif /* defined(__ToolsTemplate__DBTools__) */
