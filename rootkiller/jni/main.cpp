#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <sstream>
#include <string>
#include <sqlite/sqlite3.h>
#include "rcrypt.h"
#include <unistd.h>

using namespace std;
string list_str, my_app;

static int callback(void* data, int argc, char** argv, char** azColName) {
    for (int i = 0; i < argc; i++) {
        char *null = rcrypt("NULL");
        list_str += (argv[i] ? argv[i] : null);
        if (i < argc - 1) {
            list_str += rcrypt("|");
        }
    }
    list_str += rcrypt("\n");
    return 0;
}

void reboot_and_kill(){
   system(rcrypt("su -c killall com.pubg.imobile"));
   system(rcrypt("su -c killall com.tencent.ig"));
   system(rcrypt("su -c killall com.pubg.krmobile"));
   system(rcrypt("su -c killall com.rekoo.pubgm"));
   system(rcrypt("su -c killall com.vng.pubgmobile"));
   system(rcrypt("su -c reboot"));
}

void list() {
    sqlite3* db;
    int rc = sqlite3_open(rcrypt("/data/adb/magisk.db"), &db);
    if (rc != SQLITE_OK) {
        printf(rcrypt("ERROR CODE : 1OK72K\n"));
        std::this_thread::sleep_for(std::chrono::seconds(2));
        reboot_and_kill();
        sqlite3_close(db);
        return;
    }
    const char* query = rcrypt("SELECT * FROM policies;");
    char* errorMessage = nullptr;
    rc = sqlite3_exec(db, query, callback, nullptr, &errorMessage);
    if (rc != SQLITE_OK) {
        printf(rcrypt("ERROR CODE : 1OK73K\n"));
        std::this_thread::sleep_for(std::chrono::seconds(2));
        reboot_and_kill();
        sqlite3_free(errorMessage);
    }
    sqlite3_close(db);
}

void killback(string x){
    char *killer = rcrypt("pkill -U ");
    string cmd = killer;
    string kill = cmd+x;
    if (my_app == x){
       return;
    }
    system(kill.c_str());
}

void loop_anti_dump() {
    list();
    std::istringstream iss(list_str);
    string line;
    while (std::getline(iss, line)) {
        char *text = rcrypt("|");
        size_t pos = line.find(text);
        if (pos != string::npos) {
            string number = line.substr(0, pos);
            killback(number);
        }
    }
}

void apply_for_logo_bypass(){
  printf("APPLYING LOGO BYPASS...\n");
  std::this_thread::sleep_for(std::chrono::seconds(4));
  printf("LOGO BYPASS APPLIED SUCCESSFULLY\n");
  exit(0);
}

void power_killer(){
   while (true){
       loop_anti_dump();
       std::this_thread::sleep_for(std::chrono::seconds(3));
   }
}

int main(int argc, char* argv[]) {
   if (argc > 1) {
        //Exceptional App UID As Argv[1] (Which You Dont Want To Be Killed And Has Root Access)
        my_app = argv[1];
       /* while (true){
          loop_anti_dump();
          std::this_thread::sleep_for(std::chrono::seconds(4));
      }*/
        std::thread r_thread(power_killer);
        r_thread.join();
    } else {
       apply_for_logo_bypass();
    }
}
