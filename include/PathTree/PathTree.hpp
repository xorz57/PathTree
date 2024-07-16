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

#pragma once

#include <algorithm>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

class path_tree_t {
public:
    path_tree_t() = default;

    void add_path(const std::string &path) {
        add_path_helper(m_root, path);
    }

    void remove_path(const std::string &path) {
        remove_path_helper(m_root, path);
    }

    bool contains_path(const std::string &path) const {
        return contains_path_helper(m_root, path);
    }

    void clear() {
        clear_helper(m_root);
    }

    void show() const {
        show(m_root, 0);
    }

private:
    struct node_t {
        explicit node_t(const std::string &name) : name(name) {}
        std::vector<std::shared_ptr<node_t>> children;
        std::string name;
    };

    void add_path_helper(const std::shared_ptr<node_t> &root, const std::string &path) const {
        std::istringstream iss(path);
        std::string name;
        std::shared_ptr<node_t> current = root;
        while (std::getline(iss, name, '/')) {
            if (!name.empty()) {
                auto it = std::find_if(
                        current->children.begin(),
                        current->children.end(),
                        [&](const std::shared_ptr<node_t> &child) { return child->name == name; });
                if (it == current->children.end()) {
                    auto component = std::make_shared<node_t>(name);
                    current->children.push_back(component);
                    current = component;
                } else {
                    current = *it;
                }
            }
        }
    }

    void remove_path_helper(const std::shared_ptr<node_t> &root, const std::string &path) {
        std::istringstream iss(path);
        std::string name;
        std::shared_ptr<node_t> current = root;
        std::shared_ptr<node_t> parent = nullptr;
        while (std::getline(iss, name, '/')) {
            if (!name.empty()) {
                auto it = std::find_if(
                        current->children.begin(),
                        current->children.end(),
                        [&](const std::shared_ptr<node_t> &child) { return child->name == name; });
                if (it != current->children.end()) {
                    parent = current;
                    current = *it;
                } else {
                    return;
                }
            }
        }
        parent->children.erase(
                std::remove_if(
                        parent->children.begin(),
                        parent->children.end(),
                        [&](const std::shared_ptr<node_t> &child) { return child->name == current->name; }),
                parent->children.end());
    }

    bool contains_path_helper(const std::shared_ptr<node_t> &root, const std::string &path) const {
        std::istringstream iss(path);
        std::string name;
        std::shared_ptr<node_t> current = root;
        while (std::getline(iss, name, '/')) {
            if (!name.empty()) {
                auto it = std::find_if(
                        current->children.begin(),
                        current->children.end(),
                        [&](const std::shared_ptr<node_t> &child) { return child->name == name; });
                if (it == current->children.end()) {
                    return false;
                } else {
                    current = *it;
                }
            }
        }
        return true;
    }

    void clear_helper(std::shared_ptr<node_t> root) const {
        root->children.clear();
    }

    void show(std::shared_ptr<node_t> root, unsigned int depth) const {
        for (unsigned int i = 0; i < depth; ++i) {
            std::cout << "  ";
        }
        std::cout << root->name << std::endl;
        for (const std::shared_ptr<node_t> &child: root->children) {
            show(child, depth + 1);
        }
    }

    std::shared_ptr<node_t> m_root = std::make_shared<node_t>("/");
};
