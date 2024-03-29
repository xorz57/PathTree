#include "PathTree.hpp"

int main() {
    PathTree pathTree;
    pathTree.addPath("/bin");
    pathTree.addPath("/etc");
    pathTree.addPath("/sbin");
    pathTree.addPath("/usr/bin");
    pathTree.addPath("/usr/include");
    pathTree.addPath("/usr/lib");
    pathTree.addPath("/usr/local/bin");
    pathTree.addPath("/usr/local/lib");
    pathTree.addPath("/usr/local/man");
    pathTree.addPath("/usr/local/sbin");
    pathTree.addPath("/usr/local/share");
    pathTree.addPath("/usr/share/man");
    pathTree.addPath("/var/cache");
    pathTree.addPath("/var/lib");
    pathTree.addPath("/var/lock");
    pathTree.addPath("/var/log");
    pathTree.addPath("/var/opt");
    pathTree.addPath("/var/spool/cron");
    pathTree.addPath("/var/spool/cups");
    pathTree.addPath("/var/spool/mail");
    pathTree.addPath("/var/spool/tmp");
    pathTree.addPath("/dev");
    pathTree.addPath("/home");
    pathTree.addPath("/lib");
    pathTree.addPath("/mnt");
    pathTree.addPath("/opt");
    pathTree.addPath("/proc");
    pathTree.addPath("/root");
    pathTree.show();
    std::cout << std::boolalpha << pathTree.containsPath("/") << std::endl;
    std::cout << std::boolalpha << pathTree.containsPath("/usr") << std::endl;
    std::cout << std::boolalpha << pathTree.containsPath("/usr/local") << std::endl;
    std::cout << std::boolalpha << pathTree.containsPath("/usr/local/bin") << std::endl;
    return 0;
}
