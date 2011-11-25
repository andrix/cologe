#include "cologe_schema.h"
#include "cologe_data.h"

struct cologe_struct;

int cologe_open(cologe_struct * cl, char * filename, char* mode);

int cologe_set_schema(cologe_struct * cl, cologe_schema * schema);

int cologe_get_schema(cologe_struct * cl, cologe_schema * schema);

int cologe_write(cologe_struct * cl, cologe_data * data);

int cologe_read(cologe_struct * cl, cologe_data * buffer);

int cologe_read_columns(cologe_struct * cl, cologe_data * buffer);

int cologe_close(cologe_struct * cl);

