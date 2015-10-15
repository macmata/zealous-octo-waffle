//
// Created by alexandre leblanc on 2015-10-14.
//

#ifndef ZEALOUS_OCTO_WAFFLE_SERVER_H
#define ZEALOUS_OCTO_WAFFLE_SERVER_H

#include <vector>
#include "../../mongoose-6.0/mongoose.h"


class server{

private:
    const char * s_http_port;
    std::vector<mg_mgr*> vectorMgr;

    static void * run(void *mgMgr);
public:

    server() : s_http_port("tcp://0.0.0.0:8000") { }

    void warmup();

};

#endif //ZEALOUS_OCTO_WAFFLE_SERVER_H
