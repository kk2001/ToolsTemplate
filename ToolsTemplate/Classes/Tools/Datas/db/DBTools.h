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
#include <vector>
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

struct TestBean {
    
    std::string name;
    
};

class DBTools  {
    
public:
    
    bool createTable( DBInfo& dbInfo );
    
   // insert
    bool insertValue( DBInfo& info );
    void insertValues( std::vector<TestBean>& list, DBInfo& info );
    void insertValues( std::vector<std::string>& list, DBInfo& info  );
        
    
    // select
    std::vector<TestBean> getList( DBInfo& info );
    
    // delete
    bool deleteValues( DBInfo& info );
    
    // update
    bool updateValues( DBInfo& info );
    
    
};


#endif /* defined(__ToolsTemplate__DBTools__) */
