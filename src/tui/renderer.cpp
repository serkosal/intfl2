export module intfl.ui;

import std;

import ftxui;

import intfl.core;

using namespace std;

export ftxui::Component ftxui_render(const FileTree& file_tree) {
    ftxui::Components entries;

    stack<tuple<const FileTree::Node*, const size_t>> st; 
    st.push({&file_tree.root, 0});
    while (st.size()) {
        const auto [node, depth] = st.top(); st.pop();
        const auto [file, children] = *node;

        ftxui::MenuEntryOption options;
        options.label = format(
            L"{} {}", 
            wstring(depth, L' '), 
            file.path().filename().wstring()
        );
        if (file.is_directory()) {
            options.transform = [](ftxui::EntryState state) {
                state.label = (state.active ? "> " : "  ") + state.label;
                auto e = ftxui::text(state.label) | ftxui::color(ftxui::Color::Cyan);
                if (state.focused)
                    e |= ftxui::inverted;
                if (state.active)
                    e |= ftxui::bold;
                return e;
            };

            for (const auto& child : children)
                st.push({child.get(), depth + 1});
        }

        entries.push_back(ftxui::MenuEntry(options));
    }

    return ftxui::Container::Vertical(entries) | ftxui::frame;
}