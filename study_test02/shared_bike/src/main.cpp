#include "iniconfig.h"
#include "configdef.h"

#include "Logger.h"

//sb.exe conf/shared_bike.ini
int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Please input shbk <config file path> <log file config> !\n");
        return -1;
    }

    if (!Logger::instance()->init(std::string(argv[2]))) {
        fprintf(stderr, "init log module failed.\n");
        return -2;
    }

    Iniconfig config;
    if (!config.loadfile(std::string(argv[1]))) {
        //printf("load %s failed.\n", argv[1]);
        LOG_ERROR("load %s failed.", argv[1]);
        //Logger::instance()->GetHandle()->error("load %s failed.", argv[1]); //宏替换
         

        return -3;
    }

    st_env_config conf_args = config.getconfig();

    LOG_INFO("[database] ip: %s port: %d user: %s pwd: %s db: %s [server] port: %d\n", conf_args.db_ip.c_str(), conf_args.db_port, conf_args.db_user.c_str(), conf_args.db_pwd.c_str(), conf_args.db_name.c_str(), conf_args.svr_port);

    return 0;
}
