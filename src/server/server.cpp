//
// Created by alexandre leblanc on 2015-10-14.
//
#include <iostream>
#include "server.h"


void ev_handler(struct mg_connection *nc, int ev, void *ev_data) {
    switch (ev) {
        case MG_EV_RECV:

            break;
        case MG_EV_HTTP_REQUEST:

            break;
        default:
            break;
    }
}


void * server::run(void *mgMgr){
    while(true){
        mg_mgr_poll((mg_mgr*)mgMgr, 1000);
    }
    mg_mgr_free((mg_mgr*)mgMgr);
}

void server::warmup() {
    for (int i = 0; i < 4; ++i) {
        struct mg_mgr* mgMgr = new mg_mgr;
        vectorMgr.push_back(mgMgr);
        mg_mgr_init(mgMgr, this);
        mg_bind(mgMgr, s_http_port, ev_handler);
    }
    for(mg_mgr*mgMgr: vectorMgr){ mg_start_thread(run,mgMgr); }
    while(true){
        sleep(1);
    }
    std::cout<< "this is a test" << std::endl;
}
