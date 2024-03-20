#include <stdio.h>
#include <dlfcn.h>
#include <dirent.h>

void* load_plugin(char* path) {
    return dlopen(path, RTLD_LAZY);
}

void** load_plugins(char* plugins_path) {
    DIR* dp = opendir(plugins_path);
    struct dirent* ep;

    if (dp != NULL) {
        while ((ep = readdir(dp)) != NULL){
            printf("%s\n", ep->d_name);
        }
        closedir(dp);
        return NULL;
    } else return NULL;
}
