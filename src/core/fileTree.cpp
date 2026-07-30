export module intfl.core;

import std;

using namespace std;
namespace fs = std::filesystem;

export class FileTree {
public:
    struct Node {
        fs::directory_entry file;
        vector<shared_ptr<Node>> children;
    };

    Node root;

    FileTree(const fs::path& dir = fs::current_path());

    void update();
};

module :private;

FileTree::FileTree(const fs::path& dir) {
    { 
        fs::directory_entry entry{dir};
        if (!entry.exists()) throw "Path doesn't exists!";

        root = Node{entry}; 
    }
    queue<Node*> q; q.push(&root);

    while (q.size()) {
        auto cur_dir = q.front();

        for (const auto& entry : fs::directory_iterator(cur_dir->file)) {
            auto node = make_shared<Node>(entry);
            if (entry.is_directory()) 
                q.push(node.get());
            cur_dir->children.push_back(node);
        }

        q.pop();
    }
    
}