#include <stdio.h>
#include "cologe.h"



void error(char * msg, status) {
    printf("error: ");
    printf(msg);
    printf("\n");
    exit(status);
}

int 
main() {
    // USE CASE # 1
    //  -- implement cologe_open
    //  -- implement cologe_set_schema
    //  -- implement cologe_close
    cologe_struct * cl;
    cologe_init(cl);

    if (cologe_open(cl, "mydb.cle", "a")) // modes = a | r
        error("cologe couldn't not create the file", status);

    cologe_schema * schema;
    cologe_schema_init(schema);
    cologe_schema_add(schema, "name", COLOGNE_STRING);
    cologe_schema_add(schema, "age", COLOGNE_INT);
    cologe_schema_add(schema, "mail", COLOGNE_STRING);
    cologe_schema_add(schema, "is_single", COLOGNE_BOOL);

    cologe_set_schema(cl, schema);
    
    cologe_data * data1, data2, data3;
    cologe_data_init(data1);
    cologe_data_add(data1, "name", "andres moreira");
    cologe_data_add(data1, "age", "48");
    cologe_data_add(data1, "mail", "andres@andresmoreira.com");
    cologe_data_add(data1, "is_single", "true");

    cologe_data_init(data2);
    cologe_data_add(data2, "name", "juan perez");
    cologe_data_add(data2, "age", "28");
    cologe_data_add(data2, "mail", "juan@dont.com");
    cologe_data_add(data2, "is_single", "false");

    cologe_data_init(data3);
    cologe_data_add(data3, "name", "pedro moreira");
    cologe_data_add(data3, "age", "53");
    cologe_data_add(data3, "mail", "pedro@ira.com");
    cologe_data_add(data3, "is_single", "true");

    cologe_write(cl, data1);
    cologe_write(cl, data2);
    cologe_write(cl, data3);

    cologe_close(cl);
}
