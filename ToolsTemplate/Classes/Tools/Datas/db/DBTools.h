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

class DBTools  {
    
    
public:
    
    bool createTable(std::string db_name, std::string& sql );
    
    
};


#endif /* defined(__ToolsTemplate__DBTools__) */
