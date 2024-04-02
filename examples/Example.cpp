/*
    MIT License

    Copyright (c) 2024 George Fotopoulos

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/

#include "PathTree/PathTree.hpp"

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
