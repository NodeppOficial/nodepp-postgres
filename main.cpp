#include <nodepp/nodepp.h>
#include <nodepp/fs.h>
#include <postgres.h>

using namespace nodepp;

void onMain() {

    postgres_t db ("db://usr:pass@localhost:8000","dbName");
    auto cin = fs::std_input();

    cin.onData([=]( string_t data ){

    db.exec( data ,[]( sql_item_t args ){
        for( auto &x: args.keys() ){
             console::log( x, "->", args[x] );
        }
    });

    });

    stream::pipe( cin );

}
