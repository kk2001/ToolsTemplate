//
//  DBTools.cpp
//  ToolsTemplate
//
//  Created by cesc on 14-3-21.
//
//

#include "DBTools.h"
#include "cocos2d.h"
using namespace std;



/**
 *	创建表
 *
 *	@param	db_name	数据库名字
 *	@param	sql	执行语句
 *
 *	@return	true：成功 false：失败
 */
bool DBTools::createTable( DBInfo& info ){
    bool rlt = false;

    CCAssert( info.db_name.compare( "" ) == 0 , "表名不能为空!!!");
    CCAssert( info.sql.compare( "" ) == 0 , "执行语句不能为空!!!");
    
    
    sqlite3* contractDB;
    
    if( sqlite3_open( info.db_name.c_str(), &contractDB ) == SQLITE_OK){
        
        char* errMsg;
        
        if ( sqlite3_exec(contractDB, info.sql.c_str(), NULL, NULL, &errMsg) != SQLITE_OK) {
            rlt = false;
        }else{
            rlt = true;
        }
        
        if ( errMsg != NULL  ) {
            delete  errMsg;
            errMsg = NULL;
        }
        
    }
    
    
    sqlite3_close( contractDB);
    
    return  rlt;
}