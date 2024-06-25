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
    path_tree_t path_tree;
    path_tree.addPath("/bin");
    path_tree.addPath("/etc");
    path_tree.addPath("/sbin");
    path_tree.addPath("/usr/bin");
    path_tree.addPath("/usr/include");
    path_tree.addPath("/usr/lib");
    path_tree.addPath("/usr/local/bin");
    path_tree.addPath("/usr/local/lib");
    path_tree.addPath("/usr/local/man");
    path_tree.addPath("/usr/local/sbin");
    path_tree.addPath("/usr/local/share");
    path_tree.addPath("/usr/share/man");
    path_tree.addPath("/var/cache");
    path_tree.addPath("/var/lib");
    path_tree.addPath("/var/lock");
    path_tree.addPath("/var/log");
    path_tree.addPath("/var/opt");
    path_tree.addPath("/var/spool/cron");
    path_tree.addPath("/var/spool/cups");
    path_tree.addPath("/var/spool/mail");
    path_tree.addPath("/var/spool/tmp");
    path_tree.addPath("/dev");
    path_tree.addPath("/home");
    path_tree.addPath("/lib");
    path_tree.addPath("/mnt");
    path_tree.addPath("/opt");
    path_tree.addPath("/proc");
    path_tree.addPath("/root");
    path_tree.show();
    std::cout << std::boolalpha << path_tree.containsPath("/") << std::endl;
    std::cout << std::boolalpha << path_tree.containsPath("/usr") << std::endl;
    std::cout << std::boolalpha << path_tree.containsPath("/usr/local") << std::endl;
    std::cout << std::boolalpha << path_tree.containsPath("/usr/local/bin") << std::endl;
    return 0;
}
