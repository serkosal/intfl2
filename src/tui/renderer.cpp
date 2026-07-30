export module intfl.ui;

import std;

import ftxui;

import intfl.core;
import intfl.ui.components;

using namespace std;

export ftxui::Component ftxui_render(
    const FileTree::Node& node, 
    const size_t depth = 0
) {
    auto label = format(
        L"{}{}", 
        wstring(depth, L' '), 
        node.file.path().filename().wstring()
    );

    if (!node.file.is_directory()) return ftxui::Renderer([label]{
        return ftxui::text(label);
    });

    ftxui::Components entries;
    for (const auto& child : node.children)
        entries.push_back(ftxui_render(*child, depth + 1));

    return MyCollapsible(
        label, 
        ftxui::Container::Vertical(std::move(entries)),
        false,
        ftxui::Color::Cyan
    );
}