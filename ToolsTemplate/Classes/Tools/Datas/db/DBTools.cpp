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
    
    
    if ( contractDB != NULL)sqlite3_close( contractDB);
    
    return  rlt;
}


// -----------------------------------插入函数--------------------------------------------

bool DBTools::insertValue(DBInfo &info){
    
    sqlite3* contractDB;
    sqlite3_stmt* statement;
    
    if ( sqlite3_open(info.db_name.c_str(), &contractDB ) == SQLITE_OK) {
        
        sqlite3_prepare(contractDB, info.sql.c_str(), -1, &statement, NULL);
        if ( sqlite3_step( statement) != SQLITE_DONE) {
            CCAssert( false, "插入数据失败，检查数据是否正确" );
        }
     
        
    } // end ok
    
    if(statement)sqlite3_finalize( statement );
    if(contractDB)sqlite3_close( contractDB);
    
    return true;
}

void DBTools::insertValues(std::vector<TestBean> &list, DBInfo& info ){
    
    
}

void DBTools::insertValues(std::vector<std::string> &list ,DBInfo& info ){
    
    sqlite3* contractDB;
    sqlite3_stmt* statement;
    
    if ( sqlite3_open(info.db_name.c_str(), &contractDB ) == SQLITE_OK) {
        
        vector<string>::iterator it = list.begin();
        
        while( it != list.end()){
            
            string& sql = *it;
            
            CCAssert( sql.compare( "" ) != 0 ,  "Sql 语句为空" );
            
            
            sqlite3_prepare(contractDB, sql.c_str(), -1, &statement, NULL);
            if ( sqlite3_step( statement) != SQLITE_DONE) {
                CCAssert( false, "插入数据失败，检查数据是否正确" );
            }
            
            it++;
        } // end while
        
    } // end ok
    
    if(statement)sqlite3_finalize( statement );
    if(contractDB)sqlite3_close( contractDB);
    
    
}


