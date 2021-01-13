#include "iniconfig.h"
#include "configdef.h"

//sb.exe conf/shared_bike.ini
int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Please input shbk <config file path> !\n");
        return -1;
    }

    Iniconfig config;
    if (!config.loadfile(std::string(argv[1]))) {
        printf("load %s failed.\n", argv[1]);
        return -2;
    }

    st_env_config conf_args = config.getconfig();

    printf("[database] ip: %s port: %d user: %s pwd: %s db: %s [server] port: %d\n", conf_args.db_ip.c_str(), conf_args.db_port, conf_args.db_user.c_str(), conf_args.db_pwd.c_str(), conf_args.db_name.c_str(), conf_args.svr_port);

    return 0;
}
